/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:18:48 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/************************************************* Constructors & destructor */
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << "WrongCat parameterized constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator overload called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << RESET << "WrongCat destructor called" << std::endl;
}

/************************************************************ Public methods */
std::string const &WrongCat::getType() const
{
    return (this->_type);
}

void    WrongCat::setType(const std::string &type)
{
	this->_type = type;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongMEOW" << std::endl;
}
