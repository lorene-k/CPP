/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkSorted.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:55:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/15 12:26:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define MAUVE  "\033[38;5;177m"
#define TICK    "\u2714"
#define CROSS   "\u2718"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <fstream>

static bool isSorted(const std::vector<int> &output, const std::vector<int> &sorted)
{
    if (output.size() != sorted.size())
        return (false);
    for (size_t i = 0; i < output.size(); i++)
    {
        if (output[i] != sorted[i])
            return (false);
    }
    return (true);
}

static void getValidSequence(std::vector<int> &sorted)
{
    int n;
    std::ifstream unsorted("numbers.txt");

    if (!unsorted)
        throw std::runtime_error("could not open numbers.txt");
    while (unsorted >> n)
        sorted.push_back(n);
    unsorted.close();
    std::sort(sorted.begin(), sorted.end());
}

static void parseOutput(char **av, std::vector<int> &output)
{
    std::string outputStr(av[1]);
    size_t pos = outputStr.find("After:  ");
    int n;

   if (pos != std::string::npos)
   {
        std::istringstream nss(outputStr.substr(pos + 8));
        while (nss >> n)
            output.push_back(n);
    }
}

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./checkSorted <number1> <number2> ... <numberN>" << std::endl;
        return (1);
    }
    try
    {
        std::vector<int> sorted, output;
        getValidSequence(sorted);
        parseOutput(av, output);
        if (isSorted(output, sorted))
            std::cout << GREEN << TICK << " Sequence sorted" << RESET << std::endl;
        else
            std::cout << RED << CROSS << " Sequence not sorted" << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }    
    return (0);
}
