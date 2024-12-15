/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:04:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/15 23:37:23 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/************************************************** Constructors & destructor */
Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << RED << e.what() << ": changed to 1" << RESET << std::endl;
        _grade = 1;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << RED << e.what() << ": changed to 150" << RESET << std::endl;
        _grade = 150;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
        this->_name = other.getName();
    }
    std::cout << "Bureaucrat copy assignment operator overload called" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RESET << "Bureaucrat destructor called" << std::endl;
}

/************************************************************* Public methods */
int Bureaucrat::getGrade() const
{
    return (_grade);
}

std::string const Bureaucrat::getName() const
{
    return (_name);
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (this->_grade - 1 < 1)
            throw GradeTooHighException();
        this->_grade--;
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << RED << "Can't change grade for " << this->_name << ": " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (this->_grade + 1 > 150)
            throw GradeTooLowException();
        this->_grade++;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << RED << "Can't change grade for " << this->_name << ": " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::signForm(Form &form) // COMPLETE THIS
{
    try
    {
        form.beSigned(*this);
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << RED << "Bureaucrat " << this->_name
        << " couldn't sign " << form.getName() << " Form because " << e.what() << RESET << std::endl;
    }
}

/*********************************************************** Stream overloads */
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << GREEN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return (out);
}
