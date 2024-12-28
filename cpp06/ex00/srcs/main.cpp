/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 17:37:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void printType(int type)
{
    std::cout << MAUVE << "TYPE = ";
    switch (type)
    {
        case CHAR:
            std::cout << "char";
            break;
        case INT:
            std::cout << "int";
            break;
        case FLOAT:
            std::cout << "float";
            break;
        case DOUBLE:
            std::cout << "double";
            break;
        case PSEUDO:
            std::cout << "pseudo";
            break;
        default:
            std::cout << "invalid";
            break;
    }
    std::cout << RESET << std::endl;
}

void ScalarConverter::convert(std::string &literal)
{
    int type = detectType(literal);
    if (literal.empty() || type == -1)
    {
        std::cout << "Invalid input literal. Valid input: displayable char, int, double, float" << std::endl;
        return;
    }
    printType(type);
    display(literal, type);
}

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Usage: ./convert <value>" << std::endl;
    else
    {
        std::string literal = av[1]; 
        ScalarConverter::convert(literal);
    }
    return (0);
}
