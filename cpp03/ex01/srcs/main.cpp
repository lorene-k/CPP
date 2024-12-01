/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:11:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/02 00:01:46 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/************************************************************ ClapTrap Tests */
// static void clapConstructors()
// {
//     std::cout << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
//     ClapTrap defaultTrap;
//     ClapTrap namedTrap("TEST");
//     ClapTrap copyTrap(namedTrap);
//     ClapTrap assignedTrap;
//     assignedTrap = defaultTrap;
//     std::cout << BLUE "Function exited" << std::endl;
// }

// static void clapAttack()
// {
//     std::cout << CYAN << "===== Attack Tests =====" << RESET << std::endl;
//     ClapTrap attacker("Warrior");
//     attacker.attack("Target");
//     attacker.takeDamage(5);
//     attacker.attack("Another Target");
//     std::cout << BLUE "Function exited" << std::endl;
// }

// static void clapRepair()
// {
//     std::cout << CYAN << "===== Damage and Repair Tests =====" << RESET << std::endl;
//     ClapTrap repairTest("Doctor");
//     repairTest.takeDamage(5);
//     repairTest.beRepaired(10);
//     repairTest.takeDamage(15);
//     repairTest.beRepaired(5);
//     std::cout << BLUE "Function exited" << std::endl;
// }

/************************************************************ ScavTrap Tests */
static void scavConstructors()
{
    std::cout << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
    ScavTrap defaultTrap;
    ScavTrap namedTrap("TEST");
    ScavTrap copyTrap(namedTrap);
    ScavTrap assignedTrap;
    assignedTrap = defaultTrap;
    std::cout << BLUE "Function exited" << std::endl;
}

static void scavAttack()
{
    std::cout << CYAN << "===== Attack Tests =====" << RESET << std::endl;
    ScavTrap attacker("ScavWarrior");
    attacker.attack("Target");
    attacker.takeDamage(5);
    attacker.attack("Another Target");
    std::cout << BLUE "Function exited" << std::endl;
}

static void scavRepairKeep()
{
    std::cout << CYAN << "===== Damage, Repair & Gate keeper Tests =====" << RESET << std::endl;
    ScavTrap repairTest("ScavDoctor");
    repairTest.guardGate();
    repairTest.takeDamage(5);
    repairTest.beRepaired(10);
    repairTest.takeDamage(150);
    repairTest.beRepaired(5);
    std::cout << BLUE "Function exited" << std::endl;
}

int main()
{
    // std::cout << std::endl << CYAN << "========== CLAPTRAP TESTS ==========" << std::endl;
    // clapConstructors();
    // std::cout << std::endl;
    // clapAttack();
    // std::cout << std::endl;
    // clapRepair();
    // std::cout << std::endl;
    
    std::cout << CYAN << "\n========== SCAVTRAP TESTS ==========" << std::endl;
    scavConstructors();
    std::cout << std::endl;
    scavAttack();
    std::cout << std::endl;
    scavRepairKeep();
    std::cout << std::endl;
    
    // ClapTrap *ptr = new ScavTrap("Test");
    // delete ptr;
    return (0);
}
