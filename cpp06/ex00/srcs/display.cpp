/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:48:10 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 17:34:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ********************************************************** PRINT (HELPERS) //
static void printFloat(long double literal)
{
    if (literal > std::numeric_limits<float>::max())
        std::cout << "float: overflow" << std::endl;
    else if (literal < -std::numeric_limits<float>::max())
        std::cout << "float: underflow" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal) << "f" << std::endl;
}

static void printDouble(long double literal)
{
    if (literal > std::numeric_limits<double>::max())
        std::cout << "double: overflow" << std::endl;
    else if (literal < -std::numeric_limits<double>::max())
        std::cout << "double: underflow" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal) << std::endl;
}

static void printInt(long double literal)
{
    if (literal > std::numeric_limits<int>::max())
        std::cout << "int: overflow" << std::endl;
    else if (literal < std::numeric_limits<int>::min())
        std::cout << "int: underflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(literal) << std::endl;
}

static void printChar(long double literal)
{
    if (literal >= std::numeric_limits<char>::min()
        && literal <= std::numeric_limits<char>::max()
        && isprint(literal))
        std::cout << "char: '" << static_cast<char>(literal) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

// ****************************************************************** DISPLAY //
static void displayPseudo(std::string &literal)
{
    double value = atof(literal.c_str());
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    
}

static void displayDouble(std::string &literal)
{
    std::stringstream ss(literal);
    long double value;
    ss >> value;
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

static void displayFloat(std::string &literal)
{
    std::stringstream ss(literal);
    long double value;
    ss >> value;
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

static void displayInt(std::string &literal)
{
    std::stringstream ss(literal);
    long double value;
    ss >> value;
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void displayChar(std::string &literal)
{
    std::cout << "char: " << static_cast<char>(literal[0]) << std::endl;
    std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
}

void display(std::string &literal, int type)
{
    try
    {
        switch (type)
        {
            case PSEUDO:
                displayPseudo(literal);
                break;
            case CHAR:
                displayChar(literal);
                break;
            case INT:
                displayInt(literal);
                break;
            case DOUBLE + 1:
                displayDouble(literal);
                break;
            case FLOAT - 1:
                displayFloat(literal);
                break;
        }
    }
    catch (std::exception &e)
    {
        std::string error = (literal[0] == '-' ? "underflow" : "overflow");
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << error << std::endl;
        std::cout << "float: " << error << std::endl;
        std::cout << "double: " << error << std::endl;
    }
}
