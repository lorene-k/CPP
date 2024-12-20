/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:06:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 16:34:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


/************************************************** Constructors & destructor */
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(std::string const &msg)
{
    std::cout << "Intern parameterized constructor called with parameter: " << msg << std::endl;
}

Intern::Intern(Intern const &other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
    if (this != &other)
        *this = other;
    std::cout << "Intern copy assignment operator overload called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

/************************************************************* Public methods */
static AForm *createPardonForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *createRobotForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createShrubForm(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}


/************************************************************* Public methods */
AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    AForm *(*array[3])(std::string const &target) = {&createPardonForm, &createRobotForm, &createShrubForm};
    std::string names[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {    
            std::cout << MAUVE << "Intern creates " << names[i] << RESET << std::endl;
            return (array[i](target));
        }
    }
    std::cerr << ORANGE << "Form can't be created: name doesn't exist" << std::endl;
    return (NULL);
}
