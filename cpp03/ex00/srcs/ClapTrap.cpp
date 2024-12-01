/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:32:55 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/26 23:09:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)  : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parameterized constructor called" << std::endl;
    this->_name = name;
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
    std::cout << RESET << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
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
        std::cout << RED << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout <<  RED << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
}
