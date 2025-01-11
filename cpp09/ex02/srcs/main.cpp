/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/11 14:54:07 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 3)
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
    QUESTIONS
- accept single int as input ?
- handle duplicates as errors ?
- calculate time to display as well ? (end timer before or after display)
- accept empty strings if there are also at least 2 numbers ?

    TESTS
- handle at least 3000 different integers
- empty strs

EXAMPLES :
/PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

./PmergeMe shuf -i 1-100000 -n 3000 | tr "\n" " "
> runs exec w/ 3000 random numbers (between 1 and 100,000) displayed on a saingle line, separated by spaces

PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
> same for OSX user (macOS)
*/