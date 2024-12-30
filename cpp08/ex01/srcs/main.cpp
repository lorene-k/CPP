/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/30 10:09:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// *********************************************************** TEST FUNCTIONS //
static void emptySpan(Span &sp)
{
    std::cout << MAUVE << "\n===== SHORTEST SPAN - EMPTY CONTAINER =====" << RESET << std::endl;
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &what)
    {
        std::cout << RED << what.what() << RESET << std::endl;
    }
}

static void soloElement(Span &sp)
{
    std::cout << MAUVE << "\n===== SHORTEST SPAN - 1 ELEMENT ADDED IN CONTAINER =====" << RESET << std::endl;
    sp.addNumber(0);
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &what)
    {
        std::cout << RED << what.what() << RESET << std::endl;
    }
}

static void addingRange(Span &sp, std::vector<int> &range)
{
    std::cout << MAUVE << "\n===== ADDING RANGE =====" << RESET << std::endl;
    try
    {
        sp.addRange(range.begin(), range.end());
        std::cout << GREEN << "Range successfully added" << RESET << std::endl;
    }
    catch (std::exception &what)
    {
        std::cout << RED << what.what() << RESET << std::endl;
    }
    try
    {
        sp.addRange(range.begin(), range.end());
    }
    catch (std::exception &what)
    {
        std::cout << RED << what.what() << RESET << std::endl;
    }
}

static void spanFunctions(Span &sp)
{
    std::cout << MAUVE << "\n===== SPAN - 20 000 ELEMENTS IN CONTAINER =====" << RESET << std::endl;
    try
    {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &what)
    {
        std::cout << RED << what.what() << RESET << std::endl;
    }
}

// ****************************************************************** MY MAIN //
int main(int ac, char **av)
{
    int spanSize, rangeStart, rangeEnd;

    if (ac != 4)
    {
        spanSize = 20000;
        rangeStart = 1;
        rangeEnd = 19999;
        std::cout << "\nUsing default values: spanSize = " << spanSize << ", rangeStart = " << rangeStart << ", rangeEnd = " << rangeEnd << std::endl;
    }
    else
    {
        spanSize = std::atoi(av[1]);
        rangeStart = std::atoi(av[2]);
        rangeEnd = std::atoi(av[3]);
    }
    Span sp = Span(spanSize);
    std::vector<int> range;
    for (int i = rangeStart; i <= rangeEnd; ++i)
        range.push_back(i);

    emptySpan(sp);          // Should throw an exception
    soloElement(sp);        // Should throw an exception
    addingRange(sp, range); // Adding 1st range should work - Adding range again should throw an exception
    spanFunctions(sp);      // Longest & shortest span will be printed

    std::cout << std::endl;
    return (0);
}

// ************************************************************* SUBJECT MAIN //
// int main( void )
// {
//     Span sp = Span(5);
    
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
    
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
    
//     return (0);
// }
