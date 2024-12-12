/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:18:48 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 13:45:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/************************************************* Constructors & destructor */
Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type), _brain(new Brain())
{
    if (type != "Cat")    
        this->_type = "Cat";
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {    
        Animal::operator=(other);
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    std::cout << "Cat copy assignment operator overload called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << RESET << "Cat destructor called" << std::endl;
}

/************************************************************ Public methods */
std::string const &Cat::getType() const
{
    return (this->_type);
}

void    Cat::setType(const std::string &type)
{
	this->_type = type;
}

void    Cat::makeSound() const
{
    std::cout << "MEOW" << std::endl;
}
