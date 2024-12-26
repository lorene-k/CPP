/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:10 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/24 21:24:22 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void DisplayDouble(long double &literal, int type)
{
    if (type == PSEUDO)
        std::cout << static_cast<double>(literal);
    else if (literal < std::numeric_limits<double>::lowest())
        std::cout << "underflow" << std::endl;
    else if (literal > std::numeric_limits<double>::max())
        std::cout << "overflow" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(literal);
}

static void DisplayFloat(long double &literal, int type)
{
    if (type == PSEUDO)
        std::cout << static_cast<float>(literal) << "f";
    else if (literal < std::numeric_limits<float>::lowest())
        std::cout << "underflow";
    else if (literal > std::numeric_limits<float>::max())
        std::cout << "overflow";
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(literal) << "f";
}

static void DisplayInt(long double &literal, int type)
{
    if (type != PSEUDO)
    {
        if (literal < std::numeric_limits<int>::min())
            std::cout << "underflow";
        else if (literal > std::numeric_limits<int>::max())
            std::cout << "overflow";
        else
            std::cout << static_cast<int>(literal);
    }
}

void DisplayChar(long double &literal, int type)
{
    if (type != PSEUDO)
    {
        if (type == CHAR)
            std::cout << "'" << static_cast<char>(literal) << "'";
        else if (literal >= std::numeric_limits<char>::min()
            && literal <= std::numeric_limits<char>::max()
            && isprint(literal))
            std::cout << "'" << static_cast<char>(literal) << "'";
        else
            std::cout << "Non displayable";
    }
}

static void DisplayAll(long double &literal, int type, int currType)
{
    switch (currType)
    {
        case CHAR:
            DisplayChar(literal, type);
            break;
        case INT:
            DisplayInt(literal, type);
            break;
        case DOUBLE + 1:
            DisplayDouble(literal, type);
            break;
        case FLOAT - 1:
            DisplayFloat(literal, type);
            break;
    }
}

static bool CheckPseudo(int type, int value)
{
    if (type == PSEUDO)
    {
        if (value == CHAR || value == INT)
            std::cout << "impossible";
        return (true);
    }
    return (false);
}

void Display(std::string &literal, int type)
{
    long double value;
    std::string array[4] = {"char", "int", "float", "double"};
    try
    {
        if (type == CHAR)
            value = static_cast<long double>(literal[0]);
        else
            value = std::stold(literal);
        for (int i = 0; i < 4; i++)
        {
            std::cout << array[i] << ": ";
            CheckPseudo(type, i + 1);
            DisplayAll(value, type, i + 1);
            std::cout << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "char: Non displayable" << std::endl;
        for (int i = 1; i < 4; i++)
        {
            std::cout << array[i] << ": ";
            std::cout << (literal[0] == '-' ? "underflow" : "overflow") << std::endl;
        }
    }
}
