/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:00:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 18:02:10 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

/************************************************** Constructors & destructor */
Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
    this->_type = "ice";
    std::cout << "Ice parameterized constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
    if (this != &other)
        AMateria::operator=(other);
    std::cout << "Ice copy assignment operator overload called" << std::endl;
    return (*this);
}

Ice::~Ice()
{
    std::cout << RESET << "Ice destructor called" << std::endl;
}

/************************************************************* Public methods */
Ice *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
