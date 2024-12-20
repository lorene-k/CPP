/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:04:30 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 17:18:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************************************************** Constructors & destructor */
Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
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
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
    if (form.getSigned() == true)
        std::cout << MAUVE << "Bureaucrat " << this->_name << " signed " << form.getName() << " Form" << RESET << std::endl;
    else
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << MAUVE << this->_name << " executed " << form.getName() << " Form" << RESET << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << this->_name << " cannot execute " << form.getName() << ": " << e.what() << RESET << std::endl;
    }  
}

/*********************************************************** Grade exceptions */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Grade is too low");
}

/*********************************************************** Stream overloads */
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << GREEN << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
    return (out);
}
