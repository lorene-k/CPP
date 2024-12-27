/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/27 14:35:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void increment(int &x) {
    x++;
}

static void appendPlus(std::string &str) {
    str += "+";
}

template <typename T>
void printElement(T &elem)
{
    std::cout << elem << " ";
}

int main()
{
    std::cout << MAUVE << "\n===== INT TESTS =====" << RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    int intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intLen, increment);

    std::cout << "After incrementing: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << MAUVE << "\n===== STRING TESTS =====" << RESET << std::endl;
    std::string strArray[] = {"I", "love", "green", "apples"};
    int strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original string array: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl;

    iter(strArray, strLen, appendPlus);

    std::cout << "After appending '+': ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl << std::endl;

    return (0);
}
