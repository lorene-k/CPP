/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeExceptions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:54:33 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/15 21:54:59 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeExceptions.hpp"

const char *GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
