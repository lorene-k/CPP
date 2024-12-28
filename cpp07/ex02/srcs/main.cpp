/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 18:39:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "printTests.hpp"

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

    std::cout << MAUVE << "\n===== EMPTY ARRAY TESTS =====" << RESET << std::endl;
    Array<int> emptyArray;
    printTests(emptyArray);

    std::cout << std::endl << std::endl;
    return (0);
}
