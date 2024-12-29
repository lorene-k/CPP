/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 22:06:59 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void )
{
    std::cout << MAUVE << "\n===== TESTS =====" << RESET << std::endl;
    std::vector<int> test;
    for (int i = 0; i < 10; i++)
        test.push_back(i);
    try
    {
        std::cout << "Looking for 5 in container: ";
        std::cout << (*easyfind(test, 5)) << GREEN << " Found" << RESET << std::endl;
        std::cout << "Looking for 100 in container: ";
        std::cout << (*easyfind(test, 100)) << GREEN << "Found" << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Value not found" << RESET << std::endl;
    }
    std::cout << std::endl;
    return (0);
}