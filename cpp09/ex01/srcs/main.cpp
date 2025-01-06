/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/05 16:01:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage : ./RPN \"<expression>\"" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn;
        rpn.calculate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

/*
QUESTIONS:
- only positive integers ?
- can input start with non digit ? (no?)
*/