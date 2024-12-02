/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:18:48 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/03 00:29:18 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/************************************************* Constructors & destructor */
Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal("Cat"), _type(type)
{
    std::cout << "Cat default constructor called" << std::endl;
}
{
    std::cout << "Cat default constructor called" << std::endl;
}
{
    std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat & Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator overload called" << std::endl;
    if (this != &other)
    {
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << RESET << "Cat destructor called" << std::endl;
}

/************************************************************ Public methods */

