/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeExceptions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:52:56 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/15 21:54:19 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADEEXCEPTIONS_HPP

# define GRADEEXCEPTIONS_HPP

# include <string>

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

#endif // *********************************************** GRADEEXCEPTIONS_HPP //