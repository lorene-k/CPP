/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:18:48 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 13:25:35 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/************************************************* Constructors & destructor */
Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type)
{
    std::cout << "Cat parameterized constructor called" << std::endl;
    if (type != "Cat")    
        this->_type = "Cat";
}

Cat::Cat(Cat const &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat copy assignment operator overload called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat()
{
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
