/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/18 00:51:36 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/************************************************** Constructors & destructor */
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("defaultTarget")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/************************************************************* Public methods */
void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
    try
    {
        if (this->_signed == false)
            throw AForm::FormNotSignedException();
    }
    catch (AForm::FormNotSignedException &e)
    {
        std::cerr << RED << this->_name << " can't be executed: " << ORANGE << e.what() << RESET << std::endl;
    }
    try
    {
        if (bureaucrat.getGrade() > this->_gradeToExecute)
            throw AForm::GradeTooLowException();
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << RED << this->_name << " can't be executed by " << bureaucrat.getName() << ": " << ORANGE << e.what() << RESET << std::endl;
    }
    if  (this->_signed == true && bureaucrat.getGrade() <= this->_gradeToExecute)
        std::cout << PURPLE << this->_target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
