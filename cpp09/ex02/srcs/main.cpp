/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/06 14:01:19 by lkhalifa         ###   ########.fr       */
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
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

/*
    QUESTIONS
- accept single int ad input ?

    STEPS
PARSE
- parse input (save std::string)
- if bad input, throw Error
SORT
- sort w/ std::map (save time)
- sort w/ std::vector (save time)
DISPLAY
- display unsorted sequence
- display sorted sequence
- display time for each container

    CONTAINERS
- std::list
- std::vector

    RULES
- ARG = positive integer sequence
- sort with merge-insert sort algorithm
    > use the Ford-Johnson algorithm

- if error : std::cerr << "" std::endl;
- choose how to manage duplicates

- use at least 2 different containers
    > implement your algorithm for each container and avoid using a generic function
- handle at least 3000 different integers


DISPLAY 
• line1 : display an explicit text followed by the unsorted positive integer sequence.
• line2 : display an explicit text followed by the sorted positive integer sequence.
• line 3 : display an explicit text indicating the time used by your algorithm by specifying the first container used to sort the sequence.
• line 4 : display an explicit text indicating the time used by your algorithm by specifying the second container used to sort the positive integer sequence.
    > indicate the time used to perform all your operations, both the sorting part and the data management part
    > The format for the display of the time used to carry out your sorting is free
    but the precision chosen must allow to clearly see the difference between the two containers used

std::vector
std::deque ?

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