/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:18:47 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/15 23:42:48 by lkhalifa         ###   ########.fr       */
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
    //throw exception if grade is too high or too low ??
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
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw(GradeTooLowException());
    else if (this->_signed == false)
    {
        this->_signed = true;
        std::cout << "Bureaucrat " << bureaucrat.getName() << " signed "
        << this->_name << " Form" << std::endl;
    }
    else
        std::cout << this->_name << "Form already signed" << std::endl;
}

/*********************************************************** Stream overloads */
std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << GREEN << "Form name: " << form.getName() << ", Form signed: " << form.getSigned()
        << ", Grade to sign: " << form.getGradeToSign() << ", Grade to execute: " << form.getGradeToExecute() << RESET;
    return (out);
}