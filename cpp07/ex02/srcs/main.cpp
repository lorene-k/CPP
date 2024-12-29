/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 18:17:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// ****************************************************************** MY MAIN //
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

// ************************************************************ ATTACHED MAIN //
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }