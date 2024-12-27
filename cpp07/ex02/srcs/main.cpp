/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/27 17:31:46 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

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
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    std::cout << MAUVE << "\n===== INT TESTS =====" << RESET << std::endl;
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i;
    printTests(intArray);
    
    std::cout << MAUVE << "\n===== DOUBLE TESTS =====" << RESET << std::endl;
    Array<double> doubleArray(5);
    for (unsigned int i = 0; i < doubleArray.size(); i++)
        doubleArray[i] = i + 0.5;
    printTests(doubleArray);

    std::cout << MAUVE << "\n===== STRING TESTS =====" << RESET << std::endl;
    Array<std::string> stringArray(5);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    printTests(stringArray);

    std::cout << std::endl << std::endl;
    return (0);
}
