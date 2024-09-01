/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:06:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/01 14:40:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->_index = 0;
    std::cout << "Phonebook empty" << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "Contacts deleted" << std::endl;
}