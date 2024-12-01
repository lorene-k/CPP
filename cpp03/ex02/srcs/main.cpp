/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:11:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/02 00:03:53 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/************************************************************ FragTrap Tests */
static void fragConstructors()
{
    std::cout << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
    FragTrap defaultTrap;
    FragTrap namedTrap("TEST");
    FragTrap copyTrap(namedTrap);
    FragTrap assignedTrap;
    assignedTrap = defaultTrap;
    std::cout << BLUE "Function exited" << std::endl;
}

static void fragAttack()
{
    std::cout << CYAN << "===== Attack Tests =====" << RESET << std::endl;
    FragTrap attacker("FragWarrior");
    attacker.attack("Target");
    attacker.takeDamage(5);
    attacker.attack("Another Target");
    std::cout << BLUE "Function exited" << std::endl;
}

static void fragRepairHighFive()
{
    std::cout << CYAN << "===== Damage, Repair & High Five Tests =====" << RESET << std::endl;
    FragTrap repairTest("FragDoctor");
    repairTest.highFivesGuys();
    repairTest.takeDamage(5);
    repairTest.beRepaired(10);
    repairTest.takeDamage(150);
    repairTest.beRepaired(5);
    std::cout << BLUE "Function exited" << std::endl;
}

int main()
{
    std::cout << CYAN << "\n========== FRAGTRAP TESTS ==========" << std::endl;
    fragConstructors();
    std::cout << std::endl;
    fragAttack();
    std::cout << std::endl;
    fragRepairHighFive();
    std::cout << std::endl;
    return (0);
}