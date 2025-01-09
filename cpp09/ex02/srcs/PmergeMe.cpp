/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:52 by lkhalifa         ###   ########.fr       */
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
        throw std::runtime_error(": invalid input (empty)");
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) || i > 10)
            throw std::runtime_error(": invalid input");
    }
    long value = std::atol(str.c_str());
    if (value > std::numeric_limits<int>::max())
            throw std::runtime_error(": overflow");
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
    std::set<int> duplicateChecker;

    for (int i = 1; av[i]; i++)
    {
        checkDigit(av[i]);
        n = std::atoi(av[i]);
        if (duplicateChecker.insert(n).second == false)
            throw std::runtime_error(": duplicate");
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
static void merge(std::vector<int> &a, std::vector<int> &b, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<int> aL(n1), aR(n2), bL(n1), bR(n2);

    for (int i = 0; i < n1; i++) //Copy data to tmp vectors
    {
        aL[i] = a[start + i];
        bL[i] = b[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        aR[j] = a[mid + 1 + j];
        bR[j] = b[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) //Merge tmp vectors into main vectors
    {
        if (aL[i] < aR[j])
        {
            a[k] = aL[i];
            b[k] = bL[i];
            i++;
        }
        else
        {
            a[k] = aR[j];
            b[k] = bR[j];
            j++;
        }
        k++;
    }
    while (i < n1) //Copy remaining elements
    {
        a[k] = aL[i];
        b[k] = bL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = aR[j];
        b[k] = bR[j];
        j++;
        k++;
    }
}

static void sortMain(std::vector<int> &a, std::vector<int> &b, int start, int end)
{
    if (start >= end)
        return ;

    int mid = start + (end - start) / 2;
    sortMain(a, b, start, mid);
    sortMain(a, b, mid + 1, end);

    merge(a, b, start, mid, end);
}

void PmergeMe::sortVector()
{
    unsigned int n = this->_vec.size();
    int odd = n % 2;
    std::vector<int>    a;
    std::vector<int>    b;

    // STEP 1 - separate larger and smaller elements
    for (std::vector<int>::iterator it = this->_vec.begin(); it < (this->_vec.end() - odd); (it += 2)) //push larger nums into main chain, smaller into pend, leaving odd elem at last pos of initial vector
    {
        a.push_back(std::max(*it, *(it + 1)));
        b.push_back(std::min(*it, *(it + 1)));
    }
    // STEP 2 - sorting main chain using merge sort ?
    sortMain(a, b, 0, (n - 1 - odd) / 2);
    // for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
    //     std::cout << RED << *it << " ";
    // std::cout << RESET << std::endl;
    // for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
    //     std::cout << CYAN << *it << " ";
    // std::cout << std::endl;
    // for (std::vector<int>::iterator it = b.begin(); it != b.end(); it++)
    //     std::cout << BLUE << *it << " ";
    // std::cout << RESET << std::endl;
    
    // STEP 3 - sorting remaining smaller elements
    // STEP 4 - insert odd element ?
}

// void PmergeMe::sortStepTwo(unsigned int start, unsigned int end) //merge
// {
//     if (end <= start)
//         return ;
    
//     unsigned int mid = start + (end - start) / 2;
//     this->sortStepTwo(start, mid);
//     this->sortStepTwo(mid + 1, end);

// }

/*
pairwise comparison, recursion, and insertion

- where to leave 1st od elem ? (1st vec or a or b)


STEP 2
- sort recursively larger elements
- when sorting lrger elems, reorganize smaller elements so that the indexes match
*/
