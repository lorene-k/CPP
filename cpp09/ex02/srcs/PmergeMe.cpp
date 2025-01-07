/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/07 15:20:34 by lkhalifa         ###   ########.fr       */
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

/*********************************************************** Helper functions */
static void checkDigit(std::string const &str)
{
    if (str.empty())
        throw std::runtime_error("Error");
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
    struct timeval vStart, vEnd, qStart, qEnd;

    gettimeofday(&vStart, NULL);
    gettimeofday(&qStart, NULL);
    
    this->parse(av);
    this->sortVector();
    gettimeofday(&vEnd, NULL);
    this->sortQueue();
    gettimeofday(&qEnd, NULL);
    
    double vTime = static_cast<double>(vEnd.tv_sec - vStart.tv_sec) + (vEnd.tv_usec - vStart.tv_usec);
    double qTime = static_cast<double>(qEnd.tv_sec - qStart.tv_sec) + (qEnd.tv_usec - qStart.tv_usec);
    this->display(av, vTime, qTime);
}

void PmergeMe::parse(char **av)
{
    int n;

    for (int i = 1; av[i]; i++)
    {
        checkDigit(av[i]);
        n = std::atoi(av[i]);
        this->_vec.push_back(n);
        this->_deq.push_back(n);
    }
}

void PmergeMe::display(char **av, double vTime, double qTime)
{
    int i = 1;

    std::cout << "Before: ";
    for (; av[i]; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    std::cout << "After:  ";
    for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << (i - 1) << " elements with std::vector : "
        << std::fixed << std::setprecision(5) << vTime << " us" << std::endl;
    std::cout << "Time to process a range of " << (i - 1) << " elements with std::deque  : "
        << std::fixed << std::setprecision(5) << qTime << " us" << std::endl;
}

/*************************************************** Sorting using std::deque */
void PmergeMe::sortQueue()
{
    return ;
}

/************************************************** Sorting using std::vector */
void PmergeMe::sortVector()
{
    // STEP 1 - sorting pairs
    unsigned int n = this->_vec.size();
    int odd = n % 2;

    for (unsigned int i = 0; i < (n - odd); (i += 2))
    {
        if (this->_vec[i] > this->_vec[i + 1])
            std::swap(this->_vec[i], this->_vec[i + 1]);
    }

    // STEP 2 - sorting main chain
    sortStepTwo(0, n - 1);

    // STEP 3 - sorting remaining smaller elements
    // STEP 4 - insert odd element ?
}

void PmergeMe::sortStepTwo(unsigned int start, unsigned int end)
{
    if (end <= start)
        return ;
    
    unsigned int mid = start + (end - start) / 2;
    this->sortStepTwo(start, mid);
    this->sortStepTwo(mid + 1, end);
    
    merge(start, mid, end);
}

void    PmergeMe::merge(unsigned int start, unsigned int mid, unsigned int end)
{
    unsigned int i = start;
    unsigned int j = mid + 1;
    unsigned int k, value;

    while (i <= mid && j <= end)
    {
        if (this->_vec[i] <= this->_vec[j])
            i++;
        else
        {
            value = this->_vec[j];
            k = j;
            while (k > i)
            {
                this->_vec[k] = this->_vec[k - 1];
                k--;
            }
            this->_vec[i] = value;
            i++;
            j++;
            mid++;
        }
    }
}


/*
1. Group elements into pairs & find larger element
2. Sort larger elements into main sequence
3. Insert smaller elements (using Jacobsthal sequence)
4. Insert last number if odd

QUESTIONS:
- How to handle step 2 ?
- is using a tmp container allowed (same type but another instance)
- is another data structure necessary or should everything be done in the chosen container ?
*/
