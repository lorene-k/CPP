/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:32:25 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 13:24:07 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/************************************************* Constructors & destructor */
Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &type) : Animal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
    if (type != "Dog")
        this->_type = "Dog";
}

Dog::Dog(Dog const &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator overload called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog() {
    std::cout << RESET << "Dog destructor called" << std::endl;
}

/************************************************************ Public methods */
std::string const &Dog::getType() const
{
    return (this->_type);
}

void    Dog::setType(const std::string &type)
{
	this->_type = type;
}

void    Dog::makeSound() const
{
    std::cout << "WOUAF" << std::endl;
}
