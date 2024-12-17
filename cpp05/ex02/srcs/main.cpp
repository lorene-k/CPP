/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/18 00:51:54 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Constructors =====" << RESET << std::endl;
    PresidentialPardonForm test("target1");
    Bureaucrat bureaucrat("Bob", 1);

    std::cout << std::endl << CYAN << "===== Stream overloads =====" << RESET << std::endl;
    std::cout << bureaucrat << std::endl;
    std::cout << test  << std::endl;
    
    std::cout << std::endl << CYAN << "===== Form functions =====" << RESET << std::endl;
    test.beSigned(bureaucrat);
    bureaucrat.signForm(test);
    test.execute(bureaucrat);

    std::cout << std::endl;
    return (0);
}