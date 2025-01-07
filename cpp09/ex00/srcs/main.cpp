/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/07 07:53:19 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange btc;
        btc.parseData("databases/data.csv"); // NOT PROTECTED AGAINST INVALID DATA
        btc.parseInput(av[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}

/*
QUESTIONS:
- what to do if the date is lower than lowest date ?
- Can i accept only dates up to 2025 included ?
- return custom & accurate error messages ? Or just general "bad input" like in example ?
*/

/*
TESTS : 
- check overflows
- invalid date
- invalid data
- invalid format (separator)
*/