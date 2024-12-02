/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:32:25 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/03 00:33:36 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/************************************************* Constructors & destructor */
Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog & Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator overload called" << std::endl;
    if (this != &other) {
        // Copy member variables here
    }
    return *this;
}

Dog::~Dog() {
    std::cout << RESET << "Dog destructor called" << std::endl;
}

/************************************************************ Public methods */

