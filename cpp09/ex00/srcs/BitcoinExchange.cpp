/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/07 08:04:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************************************************** Constructors & destructor */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &databasePath) : _databasePath(databasePath) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _databasePath(src._databasePath), _exchangeRates(src._exchangeRates)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
    if (this != &src)
    {
        this->_databasePath = src._databasePath;
        this->_exchangeRates = src._exchangeRates;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/************************************************************* Parse data.csv */
void BitcoinExchange::parseData(std::string const &databasePath)
{
    std::pair<std::string, float> data;
    std::string     line;
    std::ifstream	database(databasePath.c_str());

    if (!database)
        throw std::runtime_error("could not open data.csv file.");
    std::getline(database, line);
    while (std::getline(database, line))
    {
        data = parseLine(line);
        this->_exchangeRates[data.first] = data.second;
    }
    database.close();
}

std::pair<std::string, float> BitcoinExchange::parseLine(std::string const &line) const
{
    float               value;
    std::string         date;
    std::istringstream  ss(line);

    std::getline(ss, date, ',');
    ss >> value;
    return (std::make_pair(date, value));
}

/*********************************************************** Helper functions */
static bool printError(std::string const &error)
{
    std::cout << "Error: " << error << std::endl;
    return (false);
}

static bool checkValidDay(int year, int month, int day, std::string const &line)
{
    switch (month)
    {
        case 2:
            if (day > 28 && !(day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))))
                return (printError("bad input => " + line));
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31)
                return (printError("bad input => " + line));
            break;
        case 4: case 6: case 9: case 11:
            if (day > 30)
                return (printError("bad input => " + line));
            break;
    }
    return (true);
}

static bool isValidDate(std::string const &date, std::string const &line)
{
    int                 year, month, day;
    char                d1, d2;
    std::istringstream  ss(date);

    ss >> year >> d1 >> month >> d2 >> day;
    if ((ss.fail() || date.size() != 10
        || d1 != '-' || d2 != '-')
        || !(year > 2008 && year < 2025)
        || !(month > 0 && month < 13)
        || !(day > 0 && day < 32))
        return (printError("bad input => " + line));
    return (checkValidDay(year, month, day, line));
}

static bool isValidSeparator(std::istringstream &ss, std::string const &line)
{
    char separator;
    ss >> separator;

    if (ss.fail() || separator != '|')
    {
        printError("bad input => " + line);
        return (false);
    }
    return (true);
}

static void checkRemainingValue(std::istringstream &ss, std::string const &line)
{
    bool dot = false;
    char c;

    while (ss.get(c))
    {
        if (!std::isdigit(c))
        {
            if (c == '.' && !dot)
                dot = true;
            else
            {    
                printError("bad input => " + line);
                return ;
            }
        }
    }
    printError("too large a number.");
}

static bool isValidValue(std::istringstream &ss, float *value, std::string const &line)
{
    ss >> *value;
    
    if (ss.fail() || !ss.eof())
    {
        ss.clear();
        checkRemainingValue(ss, line);
        return (false);
    }
    if (*value < 0)
        printError("not a positive number.");
    else if (*value > 1000)
        printError("too large a number.");
    if (*value < 0 || *value > 1000)
        return (false);
    return (true);
}

static void printResult(std::pair<std::string, float> const &data, float rate)
{
    std::cout << data.first << " => " << data.second << " = " << data.second * rate << std::endl;
}


/************************************************************ Parse input.txt */
void BitcoinExchange::parseInput(std::string const &inputPath)
{
    std::pair<std::string, float> data;
    std::string     line;
    float           rate;
    std::ifstream	input(inputPath.c_str());

    if (!input)
        throw std::runtime_error("could not open file.");
    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error("invalid file format.");
    while (std::getline(input, line))
    {
        rate = checkInput(line, &data);
        if (rate != -1)
            printResult(data, rate);
    }
    input.close();
}

float BitcoinExchange::checkInput(std::string const &line, std::pair<std::string, float> *data) const
{
    float               value;
    std::string         date;
    std::istringstream  ss(line);

    ss >> date;
    if (!isValidDate(date, line) || !isValidSeparator(ss, line) || !isValidValue(ss, &value, line))
        return (-1);
    *data = std::make_pair(date, value);
    return (findRate(date));
}

float BitcoinExchange::findRate(std::string const &date) const
{
    std::map<std::string, float>::const_iterator it = this->_exchangeRates.lower_bound(date);
    if (it == this->_exchangeRates.end())
        return ((--it)->second);
    return (it->second);
}