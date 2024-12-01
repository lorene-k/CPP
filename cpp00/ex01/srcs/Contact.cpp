/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:05:46 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/02 14:42:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

/******************************* GETTERS *************************************/
std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

/******************************* SETTERS *************************************/
void	Contact::set_first_name(std::string input)
{
	this->_first_name = input;
}

void	Contact::set_last_name(std::string input)
{
	this->_last_name = input;
}

void	Contact::set_nickname(std::string input)
{
	this->_nickname = input;
}

void	Contact::set_phone_number(std::string input)
{
	this->_phone_number = input;
}

void	Contact::set_darkest_secret(std::string input)
{
	this->_darkest_secret = input;
}