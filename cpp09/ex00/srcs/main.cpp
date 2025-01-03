/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/03 16:04:36 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./ex00 [filename]" << std::endl;
        return (1);
    }
    return (0);
}

/*

GOAL : Output value of a certain amount of bitcoin on a certain date

- use .csv database (= bitcoin price over time)
- input = value to display * exchange rate, according to date in database

RULES
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.

container : std::map<std::string, float>

1. parse & store values from .csv file into std::map
2. parse & store input values from .txt
3. calculate value of bitcoin on input date
4. 

*/