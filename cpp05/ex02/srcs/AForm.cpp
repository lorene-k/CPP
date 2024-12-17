/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:18:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/18 00:53:14 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//********************************************************** Helper functions */
static void handleHighGrade(const AForm::GradeTooHighException &e, int toSign, int toExecute)
{
    if (toSign < 1)
        std::cerr << RED << "Invalid grade to sign (changed to 1): " << ORANGE << e.what() << RESET << std::endl;
    if (toExecute < 1)
        std::cerr << RED << "Invalid grade to execute (changed to 1): " << ORANGE << e.what()  << RESET << std::endl;
}

static void handleLowGrade(const AForm::GradeTooLowException &e, int toSign, int toExecute)
{
    if (toSign > 150)
        std::cerr << RED << "Invalid grade to sign (changed to 150): " << ORANGE << e.what() << RESET << std::endl;
    if (toExecute > 150)
        std::cerr << RED << "Invalid grade to execute (changed to 150): " << ORANGE << e.what() << RESET << std::endl;
}

/************************************************** Constructors & destructor */
AForm::AForm() : _name("defaultName"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute) : _name(name), _signed(false),
    _gradeToSign(gradeToSign < 1 ? 1 : (gradeToSign > 150 ? 150 : gradeToSign)),
    _gradeToExecute(gradeToExecute < 1 ? 1 : (gradeToExecute > 150 ? 150 : gradeToExecute))
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    try
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw AForm::GradeTooHighException();
    }
    catch (AForm::GradeTooHighException &e)
    {
        handleHighGrade(e, gradeToSign, gradeToExecute);
    }
    try
    {
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw AForm::GradeTooLowException();
    }
    catch (AForm::GradeTooLowException &e)
    {
        handleLowGrade(e, gradeToSign, gradeToExecute);
    }
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
    try
    {
        if (bureaucrat.getGrade() > this->_gradeToSign)
            throw(AForm::GradeTooLowException());
        else if (this->_signed == true)
            std::cout << RED << this->_name << " already signed" << RESET << std::endl;
        else if (this->_signed == false)
            this->_signed = true;
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cerr << RED << this->_name << " can't be signed: " << ORANGE << e.what() << RESET << std::endl;
    }
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
    return ("Form is not signed");
}

/*********************************************************** Stream overloads */
std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << GREEN << "AForm name: " << form.getName() << ", Form signed: "
    << (form.getSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << RESET;
    return (out);
}
