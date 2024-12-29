/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 13:24:07 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void )
{
    int                 value;
    std::vector<int>    test;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        test.push_back(i);
    
    std::cout << MAUVE << "\n===== TESTS =====" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
    {
        try
        {
            value = rand() % 20;
            std::cout << "Looking for " << value << " in container: ";
            std::cout << (*easyfind(test, value)) << GREEN << " Found" << RESET << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << "Value not found" << RESET << std::endl;
        }
    }
        std::cout << std::endl;
    return (0);
}
