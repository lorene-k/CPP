/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/06 14:42:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/************************************************** Constructors & destructor */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string const &) {}

PmergeMe::PmergeMe(PmergeMe const &src) : _vec(src._vec), _lst(src._lst)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
    if (this != &src)
    {    
        this->_vec = src._vec;
        this->_lst = src._lst;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

/*********************************************************** Helper functions */
static void checkDigit(std::string const &str)
{
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) || i > 10)
            throw std::runtime_error("Error");
    }

    long value = std::atol(str.c_str());
    if (value > std::numeric_limits<int>::max())
            throw std::runtime_error("Error");
}

/*********************************************************** Member functions */
void PmergeMe::process(char **av)
{
    this->parse(av);
    this->sort();
    this->display(av);
}

void PmergeMe::parse(char **av)
{
    int n;

    for (int i = 1; av[i]; i++)
    {
        checkDigit(av[i]);
        n = std::atoi(av[i]);
        this->_vec.push_back(n);
        this->_lst.push_back(n);
    }
    // std::cout << GREEN << "TEST : PRINT CONTAINERS" << RESET << std::endl;
    // for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
    // for (std::list<int>::iterator it = this->_lst.begin(); it != this->_lst.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
}

void PmergeMe::sort()
{
    return ;
}

void PmergeMe::display(char **av)
{
    (void)av;
}