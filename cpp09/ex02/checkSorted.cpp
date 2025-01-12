/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkSorted.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/12 15:00:28 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define TICK    "\u2714"
#define CROSS   "\u2718"

#include <iostream>
#include <vector>
#include <cstdlib>

static bool isSorted(const std::vector<int>& numbers)
{
    for (size_t i = 1; i < numbers.size(); ++i)
    {
        if (numbers[i] < numbers[i - 1])
            return (false);
    }
    return (true);
}

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./checkSorted <number1> <number2> ... <numberN>" << std::endl;
        return (1);
    }
    std::vector<int> numbers;
    for (int i = 1; i < ac; ++i)
        numbers.push_back(atoi(av[i]));

    if (isSorted(numbers))
        std::cout << GREEN << TICK << " Sequence sorted" << RESET << std::endl;
    else
        std::cout << RED << CROSS << " Sequence not sorted" << RESET << std::endl;
    return (0);
}
