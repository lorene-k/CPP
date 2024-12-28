/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:33:07 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 14:40:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool detectPseudo(std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff"
        || literal == "nan" || literal == "+inf" || literal == "-inf"
        || literal == "inf" || literal == "inff") 
        return (true);
    return (false);
}

static bool detectDouble(std::string &literal)
{
    size_t i = 0;
    bool dot = false;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (dot)
                return (false);
            dot = true;
        }
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

static bool detectFloat(std::string &literal)
{
    
    if (literal.size() > 3 && literal[literal.size() - 1] == 'f')
        literal.resize(literal.size() - 1);
    return (detectDouble(literal));
}

static bool detectInt(std::string &literal)
{
    size_t i = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

static bool detectChar(std::string &literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return (true);
    return (false);
}

int detectType(std::string &literal)
{
    bool (*array[5])(std::string &literal) = {&detectPseudo, &detectChar, &detectInt,
        &detectDouble, &detectFloat};
    
    for (int i = 0; i < 5; i++)
    {
        if (array[i](literal) == true)
            return (i);
    }
    return (-1);
}
