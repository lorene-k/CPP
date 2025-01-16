/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/16 18:00:16 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage : ./PMergeMe <positive int sequence>" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe pm;
        pm.process(av);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << e.what() << std::endl;
    }
    return (0);
}

/*
TODO : remove tests
? TODO : optimize algo for std::deque
? Optimize merge
*/

// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`