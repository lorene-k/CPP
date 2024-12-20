/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:18:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 17:12:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************************************************** Constructors & destructor */
AForm::AForm() : _name("defaultName"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute) : _name(name), _signed(false),
    _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    std::cout << "Form copy assignment operator overload called" << std::endl;
    return (*this);
}

AForm::~AForm()
{
    std::cout << RESET << "AForm destructor called" << std::endl;
}

/************************************************************* Getter methods */
std::string const AForm::getName() const
{
    return (_name);
}

bool AForm::getSigned() const
{
    return (_signed);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

/************************************************************* Public methods */
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw(AForm::GradeTooLowException());
    else if (this->_signed == true)
        std::cout << ORANGE << this->_name << " already signed" << RESET << std::endl;
    else if (this->_signed == false)
        this->_signed = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
    if (this->_signed == false)
        throw(AForm::FormNotSignedException());
    if (bureaucrat.getGrade() > this->_gradeToExecute)
        throw(AForm::GradeTooLowException());
    this->executeAction();
}

/*********************************************************** Grade exceptions */
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed: can't be executed");
}

/*********************************************************** Stream overloads */
std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << GREEN << "AForm name: " << form.getName() << ", Form signed: "
    << (form.getSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << RESET;
    return (out);
}
