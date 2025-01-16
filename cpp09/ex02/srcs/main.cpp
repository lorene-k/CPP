/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/16 15:25:20 by lkhalifa         ###   ########.fr       */
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
TODO handle for size <= 3
TODO : accept ac == 2 w/ args in ""
TODO  accept single int as input >> FIX
TODO calculate time to display as well >> end timer just after sequence display
TODO : optimize algo for std::deque
TODO : remove tests
? accept empty strings if there are also at least 2 numbers >> NOT CURRENTLY ACCEPTED
? check how to use offset & if is necessary
? handle duplicates as errors
? Optimize merge
*/


// TEST
// ./PmergeMe shuf -i 1-100000 -n 3000 | tr "\n" " "
// > runs exec w/ 3000 random numbers (between 1 and 100,000) displayed on a saingle line, separated by spaces
