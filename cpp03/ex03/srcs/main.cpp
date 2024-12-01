/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:11:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/02 00:09:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/************************************************************ DiamondTrap Tests */
static void diamondConstructors()
{
    std::cout << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
    DiamondTrap defaultTrap;
    DiamondTrap namedTrap("TEST");
    DiamondTrap copyTrap(namedTrap);
    DiamondTrap assignedTrap;
    assignedTrap = defaultTrap;
    std::cout << BLUE "Function exited" << std::endl;
}

static void diamondAttack()
{
    std::cout << CYAN << "===== Attack Tests =====" << RESET << std::endl;
    DiamondTrap attacker("DiamondWarrior");
    attacker.attack("Target");
    attacker.takeDamage(5);
    attacker.attack("Another Target");
    std::cout << BLUE "Function exited" << std::endl;
}

static void diamondRepair()
{
    std::cout << CYAN << "===== Repair Tests =====" << RESET << std::endl;
    DiamondTrap repairTest("DiamondDoctor");
    repairTest.takeDamage(30);
    repairTest.beRepaired(20);
    repairTest.takeDamage(150);
    repairTest.beRepaired(30);
    std::cout << BLUE "Function exited" << std::endl;
}

static void diamondSpecifics()
{
    std::cout << CYAN << "===== High Five & WhoAmI Tests =====" << RESET << std::endl;
    DiamondTrap guy("DiamondGuy");
    guy.highFivesGuys();
    guy.whoAmI();
    std::cout << BLUE "Function exited" << std::endl;
}

int main()
{
    std::cout << CYAN << "\n========== DIAMONDTRAP TESTS ==========" << std::endl;
    diamondConstructors();
    std::cout << std::endl;
    diamondAttack();
    std::cout << std::endl;
    diamondRepair();
    std::cout << std::endl;
    diamondSpecifics();
    std::cout << std::endl;
    return (0);
}