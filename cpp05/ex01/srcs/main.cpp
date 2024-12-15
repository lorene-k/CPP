/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/15 23:43:49 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Constructors =====" << RESET << std::endl;
    Bureaucrat b1("Bob", 1);
    Bureaucrat b2(b1);
    Bureaucrat b3 = b2;
    Bureaucrat b4("John", 151);

    std::cout << std::endl << CYAN << "===== Bureaucrat Stream overloads =====" << RESET << std::endl;
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    
    std::cout << std::endl << CYAN << "===== Increment/decrement =====" << RESET << std::endl;
    b1.incrementGrade();
    b2.decrementGrade();
    b4.decrementGrade();
    
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b4 << std::endl;

    std::cout << std::endl << CYAN << "===== Forms constructors =====" << RESET << std::endl;
    Form f1("Test1", 1, 1);
    Form f2("Test2", 150, 150);
    Form f3(f1);
    Form f4 = f2;
    Form f5("Test5", 0, 0);

    std::cout << std::endl << CYAN << "===== Form Stream overloads =====" << RESET << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f5 << std::endl;

    std::cout << std::endl << CYAN << "===== Form functions =====" << RESET << std::endl;
    b1.signForm(f1);
    b4.signForm(f1);
    f2.beSigned(b1);

    std::cout << std::endl;
    
    return (0);
}