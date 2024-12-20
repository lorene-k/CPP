/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 17:09:30 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Bureaucrats =====" << RESET << std::endl;
    Bureaucrat bob("Bob", 1);
    Bureaucrat john("John", 150);
    std::cout << bob << std::endl;
    std::cout << john << std::endl;

    std::cout << std::endl << CYAN << "===== Forms constructors =====" << RESET << std::endl;
    try {
    Form f1("Test1", 145, 1);
    Form f2(f1);
    Form f3 = f2;
    Form f4("Test4", 0, 151);
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl << CYAN << "===== Form Stream overloads =====" << RESET << std::endl;
    Form f1("Test1", 145, 1);
    Form f2(f1);
    Form f3 = f2;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    std::cout << std::endl << CYAN << "===== Form functions =====" << RESET << std::endl;
    try {
    bob.signForm(f1);
    bob.signForm(f1);
    john.signForm(f3);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    std::cout << f1 << std::endl << std::endl;
    return (0);
}
