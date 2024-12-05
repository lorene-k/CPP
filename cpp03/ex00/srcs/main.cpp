/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:11:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/05 11:59:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void testConstructors()
{
    std::cout << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
    ClapTrap defaultTrap;
    ClapTrap namedTrap("TEST");
    ClapTrap copyTrap(namedTrap);
    ClapTrap assignedTrap;
    assignedTrap = defaultTrap;
    std::cout << BLUE "Function exited" << std::endl;
}

static void testAttack()
{
    std::cout << CYAN << "===== Attack Tests =====" << RESET << std::endl;
    ClapTrap attacker("Warrior");
    attacker.attack("Target");
    attacker.takeDamage(5);
    attacker.attack("Another Target");
    std::cout << BLUE "Function exited" << std::endl;
}

static void testDamageAndRepair()
{
    std::cout << CYAN << "===== Damage and Repair Tests =====" << RESET << std::endl;
    ClapTrap repairTest("Doctor");
    repairTest.takeDamage(5);
    repairTest.beRepaired(10);
    repairTest.takeDamage(15);
    repairTest.beRepaired(5);
    std::cout << BLUE "Function exited" << std::endl;
}

int main()
{
    std::cout << std::endl;
    testConstructors();
    std::cout << std::endl;
    testAttack();
    std::cout << std::endl;
    testDamageAndRepair();
    std::cout << std::endl;
    return (0);
}