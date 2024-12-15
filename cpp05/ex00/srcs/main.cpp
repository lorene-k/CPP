/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/15 20:59:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Constructors =====" << RESET << std::endl;
    Bureaucrat b1("Bureaucrat1", 1);
    Bureaucrat b2(b1);
    Bureaucrat b3 = b2;
    Bureaucrat b4("Bureaucrat4", 151);

    std::cout << std::endl << CYAN << "===== Stream overloads =====" << RESET << std::endl;
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

    return (0);
}