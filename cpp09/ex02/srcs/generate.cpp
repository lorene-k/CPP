/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/12 20:05:27 by lkhalifa         ###   ########.fr       */
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
        return (0);

    std::vector<int> numbers(100);
    for (int i = 0; i < atoi(av[1]); i++)
        numbers[i] = i;

    srand(time(NULL));
    std::random_shuffle(numbers.begin(), numbers.end());

    for (int num; num < numbers.size(); num++)
        std::cout << num << " ";
    return (0);
}