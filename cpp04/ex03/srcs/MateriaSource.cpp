/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:27:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/13 16:09:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "ICharacter.hpp"

/************************************************** Constructors & destructor */
MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
    // std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(AMateria *materia[4])
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = materia[i];
    // std::cout << "MateriaSource parameterized constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materias[i])
            this->_materias[i] = other._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    // std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    if (this != &other)
    {
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
    // std::cout << "MateriaSource copy assignment operator overload called" << std::endl;
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->_materias[i];
    // std::cout << "MateriaSource destructor called" << std::endl;
}

/************************************************************* Public methods */
void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = m;
            // std::cout << GREEN << "Materia learned in slot " << i << RESET << std::endl;
            return ;
        }
    }
    if (!m)
        std::cout << RED << "Can't learn Materia (null)" << RESET << std::endl;
    else
    {
        std::cout << RED << "Can't learn Materia : no slot available" << RESET << std::endl;
        delete m;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return (this->_materias[i]->clone());
    }
    return (NULL);
}
