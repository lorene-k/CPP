/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:32:25 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 13:42:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/************************************************* Constructors & destructor */
Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const &type) : Animal(type), _brain(new Brain())
{
    if (type != "Dog")
        this->_type = "Dog";
    std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {    
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Dog copy assignment operator overload called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete this->_brain;
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
