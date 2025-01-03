/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/03 15:18:53 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    
    return (0);
}

/*
- take inverted Polish mathematical expession as argument & output result
- input numbers = less than 10
- protect division by 0
- if error : std::cerr << "" std::endl;
- handle : "+ - / *"

RPN
- operators after operands

USE std::stack

Start with an empty stack.
Scan the expression from left to right.
If the current token is an operand, push it onto the stack.
If the current token is an operator, pop the top two operands from the stack, apply the operator to them, and push the result back onto the stack.
Continue this process until all tokens have been processed.
The final result is the value remaining on the stack.

*/