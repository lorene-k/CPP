/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/24 21:32:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void PrintType(int type) //TEST
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
    int type = DetectType(literal);
    if (literal.empty() || type == -1)
    {
        std::cout << "Invalid input literal. Valid input: displayable char, int, double, float" << std::endl;
        return;
    }
    PrintType(type); //TEST
    Display(literal, type);
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


/*
TESTS
- empty strings
- overflows
- underflows
- non-displayable characters
- pseudo literals
- invalid literals
- valid literals

std::cout << "Maximum value for long double: "
    << std::numeric_limits<long double>::max() << std::endl;
*/

/*

QUESTIONS
- accept 10. as float ?
- if input = 78.3, should char output be 'N' ?
*/










/*
• char
• int
• float
• double

1. detect input type
2. check overflow
3. convert

    Examples of char literals: ’c’, ’a’, ...
If a conversion to char is not displayable, prints an informative message.


    Examples of int literals: 0, -42, 42...

    Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf

    Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan







FUNCTIONS
OK - detect the type of the literal passed as parameter
- convert it from string to its actual type,
- then convert it explicitly to the three other data types.
- display the results as shown below.

If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.

CHECK OVERFLOW & UNDERFLOW + CONVERT
Char: Convert if it's a single printable character or representable in ASCII.
Int: Use functions like std::stoi (String to Integer).
Float: Use std::stof (String to Float).
Double: Use std::stod (String to Double).
If the conversion is invalid or cannot be performed, print an appropriate error message.




Pseudo-literals:
Handle special floating-point values like +inf, -inf, nan for double
and +inff, -inff, nanf for float

For each scalar type, print:

The converted value.
Informative messages for special cases

Helper Functions
identifyLiteralType(const std::string&)

Detect the type of the input string (char, int, float, double, or pseudo-literal).
Return an enum or constant representing the type.
isPseudoLiteral(const std::string&)

________________________________________________________________________________________

void ScalarConverter::convert(const std::string& literal) {
    try {
        double value;

        if (isPseudoLiteral(literal)) {
            value = std::stod(literal);
            printConversionResults(value);
            return;
        }

        if (isCharLiteral(literal)) {
            value = static_cast<double>(literal[1]);
        } else if (isIntLiteral(literal)) {
            value = std::stoi(literal);
        } else if (isFloatLiteral(literal)) {
            value = std::stof(literal);
        } else if (isDoubleLiteral(literal)) {
            value = std::stod(literal);
        } else {
            throw std::invalid_argument("Invalid literal");
        }

        printConversionResults(value);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

*/