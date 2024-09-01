/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/01 14:17:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook   container;
    
    return (0);
}

/*
- 2 classes :

    PHONEBOOK (= container for contacts)
    - has an array of contacts
    - can store max 8 contacts
    - if user adds 9th, replace oldest by new contact
    (no dynamic allocation)

    CONTACT (1 contact w/ spec attributes)
    = 1 phonebook contact


- start w/ empty phonebook
- prompt user to enter either : ADD, SEARCH, EXIT
- other input = discarded

- CMDS :

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

    EXIT = quit prog
*/
