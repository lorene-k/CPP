/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:14:16 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 18:32:20 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/************************************************** Constructors & destructor */
Character::Character() : _name("default")
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
    std::cout << "Character parameterized constructor called" << std::endl;
}

Character::Character(Character const &other) : _name(other._name)
{
   for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            this->_materias[i] = other._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
            delete this->_materias[i];
        for (int i = 0; i < 4; i++)
        {
            if (other._materias[i])
                this->_materias[i] = other._materias[i]->clone();
            else
                this->_materias[i] = NULL;
        }
    }
    std::cout << "Character copy assignment operator overload called" << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete this->_materias[i];
    std::cout << RESET << "Character destructor called" << std::endl;
}

/************************************************************* Public methods */
std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->_materias[idx])
        this->_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && this->_materias[idx])
        this->_materias[idx]->use(target);
}
