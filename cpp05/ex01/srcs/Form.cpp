/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:18:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/18 19:22:20 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/************************************************** Constructors & destructor */
Form::Form() : _name("defaultName"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    std::cout << "Form copy assignment operator overload called" << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << RESET << "Form destructor called" << std::endl;
}

/************************************************************* Getter methods */
std::string const Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

/************************************************************* Public methods */
void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->_signed == true)
        std::cout << RED << this->_name << " Form already signed" << RESET << std::endl;
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw(Form::GradeTooLowException());
    else if (this->_signed == false)
        this->_signed = true;
}

/*********************************************************** Grade exceptions */
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade is too low");
}

/*********************************************************** Stream overloads */
std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << GREEN << "Form name: " << form.getName() << ", Form signed: "
    << (form.getSigned() ? "Yes" : "No") << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << RESET;
    return (out);
}
