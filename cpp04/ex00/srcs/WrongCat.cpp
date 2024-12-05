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

WrongCat::WrongCat(std::string type) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat parameterized constructor called" << std::endl;
    _type = type;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator overload called" << std::endl;
    if (this != &other)
    {    
        WrongAnimal::operator=(other);
        this->_type = other._type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << RESET << "WrongCat destructor called" << std::endl;
}

/************************************************************ Public methods */
void    WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
