/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 16:49:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Constructors =====" << RESET << std::endl;
    try {
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2(b1);
    Bureaucrat b3 = b2;
    Bureaucrat b4("Bureaucrat4", 151);
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    std::cout << std::endl << CYAN << "===== Increment/decrement =====" << RESET << std::endl;
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2(b1);
    Bureaucrat b3 = b2;
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    
    try {
        b1.incrementGrade();
        b2.decrementGrade();
        Bureaucrat b4("Bureaucrat4", 150); 
        b4.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << RED << "Can't change grade for " << b1.getName() << ": " << e.what() << RESET << std::endl;
    }
    return (0);
}
