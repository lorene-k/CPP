/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTests.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:28:44 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 19:52:06 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTTESTS_HPP

# define PRINTTESTS_HPP

# include "Array.hpp"
# include <iostream>
# include <string>

template <typename T>
void printTests(Array<T> &array)
{
    std::cout << "Size: " << array.size() << std::endl;

    std::cout << "Values: ";
    for (unsigned int i = 0; i < array.size(); i++)
        std::cout << array[i] << "; ";
    std::cout << std::endl;

    try
    {
        std::cout << "Value at array[4] = "<< array[4] << std::endl;
        std::cout << "Value at array[5] = "<< array[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Index out of range" << RESET << std::endl;
    }
}

#endif // ********************************************************* ARRAY_HPP //