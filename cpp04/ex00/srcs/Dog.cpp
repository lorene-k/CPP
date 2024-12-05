/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:32:25 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/************************************************* Constructors & destructor */
Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal("Dog")
{
    std::cout << "Dog parameterized constructor called" << std::endl;
    _type = type;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator overload called" << std::endl;
    if (this != &other)
    {    
        Animal::operator=(other);
        this->_type = other._type;
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << RESET << "Dog destructor called" << std::endl;
}

/************************************************************ Public methods */
void    Dog::makeSound() const
{
    std::cout << "Wouaf" << std::endl;
}
