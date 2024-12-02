/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:12:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/03 00:12:47 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/************************************************* Constructors & destructor */
Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal parameterized constructor called for " << this->_name << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal & Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator overload called" << std::endl;
    if (this != &other)
    {
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << RESET << "Animal destructor called for " << this->_name << std::endl;
}

/************************************************************ Public methods */

