/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/30 09:08:21 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( void )
{
    int                 value;
    std::vector<int>    container;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        container.push_back(i);
    
    std::cout << MAUVE << "\n===== CONTAINER =====" << RESET << std::endl;
    std::cout << "Size = " << container.size() << std::endl;
    std::cout << "Content = " << container.at(0) << " " << container.at(1) << " " << container.at(2) << " " << container.at(3) << " " << container.at(4)
        << " " << container.at(5) << " " << container.at(6) << " " << container.at(7) << " " << container.at(8) << " " << container.at(9) << std::endl;
    
    std::cout << MAUVE << "\n===== TESTS =====" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
    {
        try
        {
            value = rand() % 20;
            std::cout << "Looking for " << value << " in container: ";
            std::cout << (*easyfind(container, value)) << GREEN << " Found" << RESET << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED << "Value not found" << RESET << std::endl;
        }
    }
        std::cout << std::endl;
    return (0);
}
