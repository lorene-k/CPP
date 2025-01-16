/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/16 15:28:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP

# define PMERGEME_HPP

# define RESET  "\033[0m"
# define RED    "\033[0;31m"
# define ORANGE "\033[0;38;5;208m"
# define YELLOW "\033[0;33m"
# define GREEN  "\033[0;32m"
# define BLUE   "\033[0;34m"
# define CYAN   "\033[0;36m"
# define PURPLE "\033[0;35m"
# define MAUVE  "\033[38;5;177m"

# include <iostream>
# include <string>
# include <limits>
# include <algorithm>
# include <vector>
# include <deque>
# include <sys/time.h>
# include <unistd.h>
# include <iomanip>
# include <set>

class PmergeMe
{
private:
    std::vector<int>    _vec;
    std::deque<int>     _deq;
    double              handleVector(char **av);
    double              handleQueue(char **av);
    void                checkNum(std::string const &str);
    void                sortVector();
    void                sortQueue();
    void                display(char **av, double vTime, double qTime);

public:
    PmergeMe();
    PmergeMe(std::string const &);
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();

    void                process(char **av);
    
    template <typename T>
    void parse(char **av, T &container)
    {
        int n;
        std::set<int> duplicateChecker;
    
        for (int i = 1; av[i]; i++)
        {
            checkNum(av[i]);
            n = std::atoi(av[i]);
            if (duplicateChecker.insert(n).second == false)
                throw std::runtime_error(": duplicate");
            container.push_back(n);
        }
    }
    
    template <typename T>
    int checkSize(T &container, unsigned int n)
    {
        if (n == 3 && container[1] > container[2])
            std::swap(container[1], container[2]);
        if (n != 1 && n <= 3 && container[0] > container[1])
            std::swap(container[0], container[1]);
        if (n <= 3)
            return (1);
        return (0);
    }
};

template <typename T>
void merge(T &a, T &b, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    T mergedA, mergedB;

    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            mergedA.push_back(a[i]);
            mergedB.push_back(b[i]);
            i++;
        }
        else
        {
            mergedA.push_back(a[j]);
            mergedB.push_back(b[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        mergedA.push_back(a[i]);
        mergedB.push_back(b[i]);
        i++;
    }
    while (j <= end)
    {
        mergedA.push_back(a[j]);
        mergedB.push_back(b[j]);
        j++;
    }
    for (int k = 0; k < (int)mergedA.size(); k++)
    {
        a[start + k] = mergedA[k];
        b[start + k] = mergedB[k];
    }
}

template <typename T>
T generateJacobsthal(size_t n)
{
    T jacobsthal(n);
    jacobsthal[0] = 0;
    jacobsthal[1] = 1;
    for (size_t i = 2; i < n; i++)
        jacobsthal[i] = jacobsthal[i - 1] + (2 * jacobsthal[i - 2]);
    return (jacobsthal);
}

/************************************************************* Test functions */
template <typename T>
static void printTests(T &a, T &b, std::string str)
{
    std::cout << MAUVE << str << RESET << std::endl;
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++) //print main chain
        std::cout << CYAN << *it << " ";
    std::cout << std::endl;
    for (std::vector<int>::iterator it = b.begin(); it != b.end(); it++) //print pend
        std::cout << BLUE << *it << " ";
    std::cout << RESET << std::endl << std::endl;
}

template <typename T>
static void insertionDebug(std::string title, const char *color, T &jacobsthal, int i, T &a, T &b, int index, int pos, int offset)
{
    std::cout << color << title << RESET << std::endl;
    std::cout << "jacobsthal[i] = " << jacobsthal[i] << std::endl;
    std::cout << "POS determined from binary search : pos = " << pos << " (start = 0; end = " << a.size() - 1 - offset << std::endl;
    std::cout << "INSERT at : a.begin() + pos = " << *a.begin() + pos << "; value to insert = " << b[index] << std::endl;
    std::cout << std::endl;
}

template <typename T>
static void testContainer(T &container, const char *color, std::string title)
{
    std::cout << color << title;
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
}

#endif // *********************************************************** PMERGEME_HPP //
