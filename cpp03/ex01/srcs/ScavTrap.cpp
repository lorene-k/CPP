/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:37:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/29 17:59:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap")
{
    std::cout << "Default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)  : ClapTrap(name)
{
    std::cout << "Parameterized constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    this->_name = name;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(const ClapTrap &other)
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

ScavTrap::~ScavTrap()
{
    std::cout << RESET << "Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0 || this->_hitPoints > 0)
    {
        this->_energyPoints--;
        std::cout << GREEN << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
    else if (this->_energyPoints <= 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
}