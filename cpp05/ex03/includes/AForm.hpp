/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:00:37 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/19 14:07:32 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP

# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
protected:
    std::string const   _name;
    bool                _signed;
    int const           _gradeToSign;
    int const           _gradeToExecute;

public:
    AForm();
    AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();

    std::string const getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const &bureaucrat);
    void execute(Bureaucrat const &bureaucrat) const;
    virtual void executeAction() const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif // ***************************************************** FORM_HPP //

