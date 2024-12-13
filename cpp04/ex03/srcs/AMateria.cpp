/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:57:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/13 15:33:21 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

/************************************************** Constructors & destructor */
AMateria::AMateria() : _type("default")
{
    // std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    // std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type)
{
    // std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    if (this != &other)
        _type = other._type;
    // std::cout << "AMateria copy assignment operator overload called" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << RESET << "AMateria destructor called" << std::endl;
}

/************************************************************* Public methods */
std::string const &AMateria::getType() const
{
    return (_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* uses some " << _type << " on " << target.getName() << " *" << std::endl;
}
