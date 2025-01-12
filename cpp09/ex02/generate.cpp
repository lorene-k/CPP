/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/12 11:13:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main(int ac, char **av)
{
    if (ac < 2)
    {   
        std::cout << "Usgae: ./generate <number of elements>" << std::endl;
        return (0);
    }

    int n = atoi(av[1]);
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        numbers[i] = i;

    srand(time(NULL));
    std::random_shuffle(numbers.begin(), numbers.end());

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    return (0);
}
