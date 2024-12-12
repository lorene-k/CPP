/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:05:16 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 18:24:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

/************************************************** Constructors & destructor */
Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const &type) : AMateria(type)
{
    this->_type = "cure";
    std::cout << "Cure parameterized constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
    if (this != &other)
        AMateria::operator=(other);
    std::cout << "Cure copy assignment operator overload called" << std::endl;
    return (*this);
}

Cure::~Cure()
{
    std::cout << RESET << "Cure destructor called" << std::endl;
}

/************************************************************* Public methods */
Cure *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
