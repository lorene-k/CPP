/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/20 18:40:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string &literal)
{
    
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
• char
• int
• float
• double

1. detect input type
2. check overflow
3. convert

    Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as
inputs.
If a conversion to char is not displayable, prints an informative message.


    Examples of int literals: 0, -42, 42...

    Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff and nanf

    Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan

FUNCTIONS
- detect the type of the literal passed as parameter
- convert it from string to its actual type,
- then convert it explicitly to the three other data types.
- display the results as shown below.

If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.
*/