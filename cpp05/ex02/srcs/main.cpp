/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/19 11:09:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Constructors =====" << RESET << std::endl;
    PresidentialPardonForm pardon("target1");
    RobotomyRequestForm robot("target2");
    ShrubberyCreationForm shrub("target3");
    Bureaucrat bob("Bob", 150);
    Bureaucrat john("John", 1);

    std::cout << std::endl << CYAN << "===== Stream overloads =====" << RESET << std::endl;
    std::cout << bob << std::endl;
    std::cout << john << std::endl;
    std::cout << pardon  << std::endl;
    std::cout << robot << std::endl;
    
    std::cout << std::endl << CYAN << "===== Presidential Pardon Form =====" << RESET << std::endl;
    try {
    // pardon.beSigned(john);
    // pardon.beSigned(bob);
    john.signForm(pardon);
    pardon.execute(john);
    pardon.execute(bob);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << std::endl << CYAN << "===== Robotomy Request Form =====" << RESET << std::endl;
    srand(time(NULL));
    try {
    // robot.beSigned(john);
    // robot.beSigned(bob);
    john.signForm(robot);
    robot.execute(john);
    bob.executeForm(robot);
    robot.execute(bob);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << std::endl << CYAN << "===== Shrubbery Creation Form =====" << RESET << std::endl;
    try {
    // shrub.beSigned(john);
    // shrub.beSigned(bob);
    john.signForm(shrub);
    shrub.execute(john);
    shrub.execute(bob);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    // std::cout << std::endl;
    return (0);
}
