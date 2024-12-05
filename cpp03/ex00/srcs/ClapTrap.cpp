/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:32:55 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/05 11:53:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/************************************************* Constructors & destructor */
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)  : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parameterized constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator overload called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << RESET << "Destructor called for " << this->_name << std::endl;
}

/************************************************************ Public methods */
void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_energyPoints--;
        std::cout << GREEN << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else if (this->_energyPoints <= 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " can't attack: no energy points left!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " can't attack: no hit points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        this->_hitPoints -= amount;
        if (this->_hitPoints < 0)
            this->_hitPoints = 0;
        std::cout << ORANGE << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    }
    else if (this->_hitPoints == 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " can't take damage: no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_hitPoints += amount;
        this->_energyPoints--;
        std::cout << GREEN << "ClapTrap " << this->_name << " has been repaired by " << amount << " points!" << std::endl;
    }
    else if (this->_energyPoints <= 0)
        std::cout << RED << "ClapTrap " << this->_name << " can't be repaired: no energy points left!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " can't be repaired: no hit points left!" << std::endl;
}
