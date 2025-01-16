/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/16 18:01:50 by lkhalifa         ###   ########.fr       */
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
    std::cout << "Time to process a range of " << (i - 1) << " elements with std::vector : "
        << std::fixed << std::setprecision(5) << vTime << " s" << std::endl;
    std::cout << "Time to process a range of " << (i - 1) << " elements with std::deque  : "
        << std::fixed << std::setprecision(5) << qTime << " s" << std::endl << std::endl;
}

/*************************************************** Sorting using std::deque */
static std::deque<int>::iterator queueBinarySearch(std::deque<int>::iterator start, std::deque<int>::iterator end, int key)
{
    while (start != end)
    {
        std::deque<int>::iterator mid = start;
        if (*mid == key)
            return (mid);
        if (*mid > key)
            end = mid;
        else
        {
            start = mid;
            ++start;
        }
        std::advance(mid, std::distance(start, end) / 2); // Maybe switch order (place below iterator init ?)
    }
    return (start);
}

static void queueInsertion(std::deque<int> &a, std::deque<int> &b, int start, int end)
{
    std::deque<int> jacobsthal = generateJacobsthal<std::deque<int> >(b.size() + 1);
    std::set<int>   processed;
    int             prevIndex = 1;

    if (start == 0 && end == static_cast<int>(a.size()) - 1)
    {
        for (int i = 0; i < 2; i++)
        {
            std::deque<int>::iterator pos = queueBinarySearch(a.begin(), a.end(), b[i]);
            a.insert(pos, b[i]);
            processed.insert(i);
        }
        for (int i = 3; i < static_cast<int>(jacobsthal.size()); i++)
        {
            int index = jacobsthal[i];
            if (index >= static_cast<int>(b.size()))
                index = b.size() - 1;
            for (int j = index; j > prevIndex; j--)
            {
                if (processed.find(j) != processed.end())
                    continue;
                std::deque<int>::iterator pos = queueBinarySearch(a.begin(), a.end(), b[j]);
                a.insert(pos, b[j]);
                processed.insert(j);
            }
            if (processed.size() == b.size())
                break;
            prevIndex = index;
        }
    }
}

static void queueMergeInsertion(std::deque<int> &a, std::deque<int> &b, int start, int end)
{
    if (start >= end)
        return ;

    int mid = start + (end - start) / 2;
    queueMergeInsertion(a, b, start, mid);
    queueMergeInsertion(a, b, mid + 1, end);

    merge(a, b, start, mid, end);
    queueInsertion(a, b, start, end);
}

void PmergeMe::sortQueue() // Change loop to adapt to bidirectionnal iterators
{
    std::deque<int>::iterator it = this->_deq.begin();
    std::deque<int>::iterator ite = this->_deq.end();
    unsigned int n = this->_deq.size();
    int odd = n % 2;
    std::deque<int> a;
    std::deque<int> b;

    if (checkSize(this->_vec, n))
        return ;
    while (std::distance(it, ite) > odd)
    {
        std::deque<int>::iterator next = it;
        std::advance(next, 1);
        a.push_back(std::max(*it, *next));
        b.push_back(std::min(*it, *next));
        std::advance(it, 2);
    }
    if (odd)
        b.push_back(*(this->_deq.rbegin()));
    queueMergeInsertion(a, b, 0, (n - 1 - odd) / 2);
    this->_deq = a;
    return ;
}

double PmergeMe::handleQueue(char **av)
{
    struct timeval qStart, qEnd;

    gettimeofday(&qStart, NULL);
    this->parse(av, this->_deq);
    this->sortQueue();
    gettimeofday(&qEnd, NULL);
    double qTime = static_cast<double>(qEnd.tv_sec - qStart.tv_sec) + (qEnd.tv_usec - qStart.tv_usec) / 1e6;
    return (qTime);
}

/************************************************** Sorting using std::vector */
static int vectorBinarySearch(std::vector<int> &a, int start, int end, int key)
{
    while (start <= end)
    {   
        int mid = start + (end - start) / 2;
        if (a[mid] == key)
            return (mid);
        if (a[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return (start);
}

static void vectorInsertion(std::vector<int> &a, std::vector<int> &b, int start, int end)
{
    std::vector<int>    jacobsthal = generateJacobsthal<std::vector<int> >(b.size() + 1); // check the "+1" adjustment (for b.size() == 3)
    std::set<int>       processed;
    int                 offset;
    int                 index;
    int                 pos;
    int                 prevIndex = 1;

    if (start == 0 && end == static_cast<int>(a.size()) - 1)
    {
        for (int i = 0; i < 2; i++)
        {
            pos = vectorBinarySearch(a, 0, (int)a.size() - 1, b[i]);
            a.insert(a.begin() + pos, b[i]);
            processed.insert(i);
        }
        for (int i = 3; i < (int)jacobsthal.size(); i++)
        {
            offset = 0;
            index = jacobsthal[i];
            if (index >= (int)b.size())
                index = b.size() - 1;
            for (int j = index; j > prevIndex; j--)
            {
                pos = vectorBinarySearch(a, 0, (int)a.size() - 1 - offset, b[j]);
                a.insert(a.begin() + pos, b[j]);
                processed.insert(j);
                offset++;
            // insertionDebug("MAIN LOOP", RED, jacobsthal, i, a, b, index, pos, offset); // TESTS
            // printTests(a, b, "INSERTION TESTS"); // TESTS
            }
            if (processed.size() == b.size())
                break;
            prevIndex = index;
        }
    }
}

static void vectorMergeInsertion(std::vector<int> &a, std::vector<int> &b, int start, int end)
{
    if (start >= end)
        return ;

    int mid = start + (end - start) / 2;
    vectorMergeInsertion(a, b, start, mid);
    vectorMergeInsertion(a, b, mid + 1, end);
    merge(a, b, start, mid, end);
    vectorInsertion(a, b, start, end);
}

void PmergeMe::sortVector()
{
    unsigned int n = this->_vec.size();
    int odd = n % 2;
    std::vector<int>    a;
    std::vector<int>    b;

    if (checkSize(this->_vec, n))
        return ;
    for (std::vector<int>::iterator it = this->_vec.begin(); it < (this->_vec.end() - odd); (it += 2))
    {
        a.push_back(std::max(*it, *(it + 1)));
        b.push_back(std::min(*it, *(it + 1)));
    }
    if (odd)
        b.push_back(*(this->_vec.rbegin()));
    vectorMergeInsertion(a, b, 0, (n - 1 - odd) / 2);
    this->_vec = a;
}

double PmergeMe::handleVector(char **av)
{
    struct timeval vStart, vEnd;

    gettimeofday(&vStart, NULL);
    this->parse(av, this->_vec);
    this->sortVector();
    gettimeofday(&vEnd, NULL);
    double vTime = static_cast<double>(vEnd.tv_sec - vStart.tv_sec) + (vEnd.tv_usec - vStart.tv_usec) / 1e6;
    return (vTime);
}
