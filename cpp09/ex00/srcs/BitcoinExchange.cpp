/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/05 16:45:44 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/************************************************** Constructors & destructor */
BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string const &databasePath) : _databasePath(databasePath)
{
    std::cout << "BitcoinExchange parameterized constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _databasePath(src._databasePath), _exchangeRates(src._exchangeRates)
{
    *this = src;
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
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

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

/************************************************************* Public methods */
void BitcoinExchange::printData() const
{
    std::cout << "BitcoinExchange data:" << std::endl;
    std::cout << "Database path: " << this->_databasePath << std::endl;
    std::cout << "Exchange rates:" << std::endl;
    for (std::map<std::string, float>::const_iterator it = this->_exchangeRates.begin(); it != this->_exchangeRates.end(); it++)
        std::cout << it->first << " : " << it->second << std::endl;
}

void BitcoinExchange::loadData(std::string const &databasePath) 
{
    std::pair<std::string, float> data;
    std::string     line;
    std::ifstream	database(databasePath);

    if (!database)
        throw std::runtime_error("could not open data.csv file.");
    while (std::getline(database, line))
    {
        if (database.eof())
			break ;
        data = parseData(line);
        this->_exchangeRates[data.first] = data.second;
    }
    database.close();
}

std::pair<std::string, float> BitcoinExchange::parseData(std::string const &line) const
{
    float               value;
    std::string         date;
    std::istringstream  strStream(line);

    std::getline(strStream, date, ',');
    strStream >> value;
    return (std::make_pair(date, value));
}

/*
STEPS
- Process the Bitcoin database and store the data in a container (e.g., std::map) for efficient date-based lookup.
- Parse the input file, validate the data, and compute the required outputs.
- Handle invalid dates, negative values, and out-of-range values gracefully.


File Parsing:
Read and parse the Bitcoin database CSV file.
Read and parse the input file for dates and values.
Data Validation:
Ensure dates are in the correct YYYY-MM-DD format.
Check values are positive and within the valid range (0 to 1000).
Data Storage:
Use a container (e.g., std::map) to store Bitcoin exchange rates, with dates as keys and rates as values.
Computation:
For each line in the input file, multiply the value by the corresponding exchange rate from the Bitcoin database.
Error Handling:
Display appropriate error messages for invalid dates, values, or missing exchange rates.

*/