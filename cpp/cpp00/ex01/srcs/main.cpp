/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/02 15:37:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook   book;
    std::string input;
    
    while (input != "EXIT")
    {
        std::cout << "Enter a command> ";
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

/*
- 2 classes - OK

    PHONEBOOK (= container for contacts)
    - has an array of contacts
    - can store max 8 contacts
    - if user adds 9th, replace oldest by new contact <<<<<<<<
    (no dynamic allocation)

    CONTACT (1 contact w/ spec attributes)
    = 1 phonebook contact

main.cpp :
- start w/ empty phonebook - OK
- prompt user to enter either : ADD, SEARCH, EXIT - OK
- other input = discarded - OK
- EXIT = quit prog

phonebook.cpp :
- HANDLE CMDS :

    ADD (= save contact)
    - prompt user to input contact info
    - fields = first name, last name, nickname, phone number, and
    darkest secret. A saved contact can’t have empty fields
    - add contact to phonebook once all fileds completed

    SEARCH (= display contact)
    1. display all contacts as list of 4 columns : index, first name, last
    name and nickname
    - 1 column = 10 chars wide + '|' (except last)
    - text = right aligned
    - if text longer than column : truncate (last displayable char = replaced by '.')
    2. prompt user for index of entry to display
    - if wrong or unexisting index : display msg & prompt again
    - if ok : display contact info (1 field per line)
*/
