/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/03 14:14:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook   book;
    std::string input;
    
    while (input != "EXIT")
    {
        std::cout << "Enter a command : ADD, SEARCH or EXIT> ";
        if (!std::getline(std::cin, input))
            return (std::cout << std::endl, 0);
        if (input == "ADD")
            book.add_contact();
        else if (input == "SEARCH")
            book.search_contact();
        if (std::cin.eof())
			return (std::cout << std::endl, 0);
    }
    return (0);
}
