/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:12:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/09 19:53:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/************************************************** Constructors & destructor */
WrongAnimal::WrongAnimal() : _type("DefaultWrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
    std::cout << "WrongAnimal parameterized constructor called for " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
    std::cout << "WrongAnimal copy assignment operator overload called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called for " << this->_type << std::endl;
}

/************************************************************* Public methods */
std::string const &WrongAnimal::getType() const
{
    return (this->_type);
}

void    WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes random sound" << std::endl;
}