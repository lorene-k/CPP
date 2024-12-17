/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/18 00:17:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Constructors =====" << RESET << std::endl;
    Bureaucrat bob("Bob", 1);
    Bureaucrat john("John", 151);

    std::cout << std::endl << CYAN << "===== Bureaucrat Stream overloads =====" << RESET << std::endl;
    std::cout << bob << std::endl;
    std::cout << john << std::endl;
    
    std::cout << std::endl << CYAN << "===== Increment/decrement =====" << RESET << std::endl;
    bob.incrementGrade();
    john.decrementGrade();
    std::cout << bob << std::endl;
    std::cout << john << std::endl;
    john.incrementGrade();
    std::cout << "Grade incremented for " << john << std::endl;
    
    std::cout << std::endl << CYAN << "===== Forms constructors =====" << RESET << std::endl;
    Form f1("Test1", 149, 1);
    Form f2(f1);
    Form f3 = f2;
    Form f4("Test4", 0, 151);

    std::cout << std::endl << CYAN << "===== Form Stream overloads =====" << RESET << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    std::cout << f4 << std::endl;

    std::cout << std::endl << CYAN << "===== Form functions =====" << RESET << std::endl;
    bob.signForm(f1);
    bob.signForm(f1);
    john.signForm(f4);

    std::cout << std::endl << "BOB : " << bob << std::endl;
    std::cout << "JOHN : " << john << std::endl;
    std::cout << "F1 : " << f1 << std::endl;
    std::cout << "F4 : " << f4 << std::endl;

    std::cout << std::endl;
    
    return (0);
}