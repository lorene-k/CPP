/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 19:35:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void )
{
    std::cout << MAUVE << "\n===== VECTOR TESTS =====" << RESET << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    try
    {
        std::cout << "Looking for 5 in vector: ";
        std::cout << (*easyfind(v, 5)) << " Found" << std::endl;
        std::cout << "Looking for 100 in vector: ";
        std::cout << (*easyfind(v, 100)) << "Found" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Not found in vector" << RESET << std::endl;
    }
    std::cout << std::endl;
    return (0);
}



