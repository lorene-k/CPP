/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/17 16:13:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/************************************************** Constructors & destructor */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string const &) {}

PmergeMe::PmergeMe(PmergeMe const &src) : _vec(src._vec), _deq(src._deq)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
    if (this != &src)
    {    
        this->_vec = src._vec;
        this->_deq = src._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

/*********************************************************** Member functions */
void PmergeMe::process(char **av)
{
    double vTime = this->handleVector(av);
    double qTime = this->handleQueue(av);
    this->display(av, vTime, qTime);
}

void    PmergeMe::checkNum(std::string const &str)
{
    if (str.empty())
        throw std::runtime_error("invalid input (empty)");
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) || i > 10)
            throw std::runtime_error("invalid input");
    }
    long value = std::atol(str.c_str());
    if (value > std::numeric_limits<int>::max())
            throw std::runtime_error("overflow");
}

void PmergeMe::display(char **av, double vTime, double qTime)
{
    int i = 1;

    std::cout << std::endl << BLUE << "Before: ";
    for (; av[i]; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;
    std::cout << CYAN << "After:  ";
    for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;
    // std::cout << MAUVE << "After:  ";
    // for (std::deque<int>::iterator it = this->_deq.begin(); it != this->_deq.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << RESET << std::endl;
    std::cout << "Time to process a range of " << (i - 1) << " elements with std::vector : "
        << std::fixed << std::setprecision(5) << vTime << " s" << std::endl;
    std::cout << "Time to process a range of " << (i - 1) << " elements with std::deque  : "
        << std::fixed << std::setprecision(5) << qTime << " s" << std::endl << std::endl;
}

/*************************************************** Sorting using std::deque */
double PmergeMe::handleQueue(char **av)
{
    struct timeval qStart, qEnd;

    gettimeofday(&qStart, NULL);
    this->parse(av, this->_deq);
    this->sort(this->_deq);
    gettimeofday(&qEnd, NULL);
    double qTime = static_cast<double>(qEnd.tv_sec - qStart.tv_sec) + (qEnd.tv_usec - qStart.tv_usec) / 1e6;
    return (qTime);
}

/************************************************** Sorting using std::vector */
double PmergeMe::handleVector(char **av)
{
    struct timeval vStart, vEnd;

    gettimeofday(&vStart, NULL);
    this->parse(av, this->_vec);
    this->sort(this->_vec);
    gettimeofday(&vEnd, NULL);
    double vTime = static_cast<double>(vEnd.tv_sec - vStart.tv_sec) + (vEnd.tv_usec - vStart.tv_usec) / 1e6;
    return (vTime);
}
