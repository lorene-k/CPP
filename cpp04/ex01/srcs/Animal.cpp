/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:12:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/09 19:38:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/************************************************* Constructors & destructor */
Animal::Animal() : _type("DefaultAnimal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type)
{
    std::cout << "Animal parameterized constructor called for " << this->_type << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal & Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator overload called" << std::endl;
    if (this != &other)
        this->_type = other.getType();
    return (*this);
}

Animal::~Animal()
{
    std::cout << RESET << "Animal destructor called for " << this->_type << std::endl;
}

/************************************************************ Public methods */
std::string const &Animal::getType() const
{
    return (this->_type);
}

void    Animal::setType(const std::string &type)
{
	this->_type = type;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes random sound" << std::endl;
}
