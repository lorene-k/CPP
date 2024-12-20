/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 16:36:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    std::cout << std::endl << CYAN << "===== Intern tests =====" << RESET << std::endl;
    Intern intern;
    AForm *form1 = intern.makeForm("null", "target1");
    AForm *form2 = intern.makeForm("PresidentialPardonForm", "target2");
    AForm *form3 = intern.makeForm("RobotomyRequestForm", "target3");
    AForm *form4 = intern.makeForm("ShrubberyCreationForm", "target4");
    std::cout << std::endl;
    
    delete form1;
    delete form2;
    delete form3;
    delete form4;
    std::cout << std::endl;
    return (0);
}
