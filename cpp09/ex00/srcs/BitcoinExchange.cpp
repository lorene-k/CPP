/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/05 10:33:07 by lkhalifa         ###   ########.fr       */
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
static void printError(std::string const &error)
{
    std::cout << RED << "Error: " << error << RESET << std::endl;
}

static bool isValidDate(std::string const &date, std::string const &line)
{
    int                 year, month, day;
    char                d1, d2;
    std::istringstream  ss(date);

    ss >> year >> d1 >> month >> d2 >> day;
    if ((ss.fail() || d1 != '-' || d2 != '-')
        || !(year > 2008 && year < 2026)
        || !(month > 0 && month < 13)
        || !(day > 0 && day < 32))
    {
        printError("bad input => " + line);
        return (false);
    }
    return (true);
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

static bool isValidValue(std::istringstream &ss, float *value, std::string const &line)
{
    ss >> *value;
    
    if (ss.fail() || ss.peek() != EOF)
    {
        printError("bad input => " + line);
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
    float               rate;
    float               value;
    std::string         date;
    std::istringstream  ss(line);

    ss >> date;
    if (!isValidDate(date, line) || !isValidSeparator(ss, line) || !isValidValue(ss, &value, line))
        return (-1);
    // data = std::make_pair(date, value);
    //find rate in database
    return (1); //return rate
}

/*
- read & parse line by line
- for each line :
    OK - check date format & line format
    OK - check value format (between 0 & 1000)
    - retreive exchange rate
    - print date from input.txt + value + result (rate * value)

TESTS : 
- check overflows
- invalid date
- invalid data
- invalid format (separator)

*/