/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:37:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/01 22:34:32 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/************************************************* Constructors & destructor */
ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Scavtrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)  : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Scavtrap parameterized constructor called for" << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap): ClapTrap(scavTrap)
{
    std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Scavtrap copy assignment operator overload called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << RESET << "Scavtrap destructor called for " << this->_name << std::endl;
}

/************************************************************ Public methods */
void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 || this->_hitPoints > 0)
    {
        this->_energyPoints--;
        std::cout << GREEN << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else if (this->_energyPoints <= 0)
        std::cout <<  RED << "ScavTrap " << this->_name << " has no energy points left!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout <<  RED << "ScavTrap " << this->_name << " has no hit points left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << PURPLE << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}