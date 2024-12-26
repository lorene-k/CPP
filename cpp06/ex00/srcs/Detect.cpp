/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Detect.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:33:07 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/24 21:27:08 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool DetectPseudo(std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff"
        || literal == "nan" || literal == "+inf" || literal == "-inf"
        || literal == "inf" || literal == "inff") 
        return (true);
    return (false);
}

static bool DetectDouble(std::string &literal)
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

static bool DetectFloat(std::string &literal)
{
    
    if (literal.back() == 'f')
        literal.pop_back();
    return (DetectDouble(literal));
}

static bool DetectInt(std::string &literal)
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

static bool DetectChar(std::string &literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return (true);
    return (false);
}

int DetectType(std::string &literal)
{
    bool (*array[5])(std::string &literal) = {&DetectPseudo, &DetectChar, &DetectInt,
        &DetectDouble, &DetectFloat};
    
    for (int i = 0; i < 5; i++)
    {
        if (array[i](literal) == true)
            return (i);
    }
    return (-1);
}
