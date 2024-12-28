/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 18:21:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(T const &elem)
{
    std::cout << elem << " ";
}

int main()
{
    std::cout << MAUVE << "\n===== INT TESTS =====" << RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    int intLen = sizeof(intArray) / sizeof(intArray[0]);

    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << MAUVE << "\n===== STRING TESTS =====" << RESET << std::endl;
    std::string strArray[] = {"I", "love", "green", "apples"};
    int strLen = sizeof(strArray) / sizeof(strArray[0]);

    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl << std::endl;

    return (0);
}
