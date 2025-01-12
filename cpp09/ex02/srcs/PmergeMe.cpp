/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:35:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/12 19:48:04 by lkhalifa         ###   ########.fr       */
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
static void checkNum(std::string const &str)
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

static void printTests(std::vector<int> &a, std::vector<int> &b, std::string str)
{
    std::cout << MAUVE << str << RESET << std::endl;
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++) //print main chain
        std::cout << CYAN << *it << " ";
    std::cout << std::endl;
    for (std::vector<int>::iterator it = b.begin(); it != b.end(); it++) //print pend
        std::cout << BLUE << *it << " ";
    std::cout << RESET << std::endl << std::endl;
}

static void insertionDebug(std::string title, const char *color, std::vector<int> &jacobsthal, int i, std::vector<int> &a, std::vector<int> &b, int index, int pos, int offset)
{
    std::cout << color << title << RESET << std::endl;
    std::cout << "jacobsthal[i] = " << jacobsthal[i] << std::endl;  //TESTS
    std::cout << "POS determined from binary search : pos = " << pos << " (start = 0; end = " << a.size() - 1 - offset << std::endl;
    std::cout << "INSERT at : a.begin() + pos = " << *a.begin() + pos << "; value to insert = " << b[index] << std::endl;
    std::cout << std::endl;
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
    gettimeofday(&qEnd, NULL); // PB: dissociate time (qEND always > vEND here)
    
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
        checkNum(av[i]);
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

    for (int i = 0; i < n1; i++) //Copy data to tmp
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
    while (i < n1 && j < n2) //Merge tmp into main vectors
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

static std::vector<int> generateJacobsthal(int n)
{
    std::vector<int> jacobsthal(n);
    jacobsthal[0] = 0;
    jacobsthal[1] = 1;
    for (int i = 2; i < n; i++)
        jacobsthal[i] = jacobsthal[i - 1] + (2 * jacobsthal[i - 2]);
    return (jacobsthal);
}

static int binarySearch(std::vector<int> &a, int start, int end, int n)
{
    while (start <= end)
    {   
        int mid = start + (end - start) / 2;
        if (a[mid] > n)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return (start);
}

// static void insertion(std::vector<int> &a, std::vector<int> &b, int start, int end)
// {
//     std::vector<int>    jacobsthal = generateJacobsthal(b.size());
//     std::set<int>       processed;
//     int                 offset;
//     int                 index;
//     int                 pos;
//     int                 prevIndex = 1;

//     if (start == 0 && end == static_cast<int>(a.size()) - 1)
//     {
//         for (int i = 0; i < 2; i++)
//         {
//             // std::cout << "Value to insert = " << b[i] << std::endl;  // TESTS
//             // std::cout << "jacobsthal index = " << jacobsthal[i] << std::endl << std::endl;
//             // printTests(a, b, "PRE LOOP TESTS");
//             pos = binarySearch(a, 0, (int)a.size() - 1, b[i]);
//             a.insert(a.begin() + pos, b[i]);
//             processed.insert(i);
//         }
//         for (int i = 3; i < (int)jacobsthal.size() - 1; i++)
//         {
//             index = jacobsthal[i];
//             if (index >= (int)b.size())
//                 index = b.size() - 1;
//             // if (processed.find(index) != processed.end())
//             //         continue;
//             pos = binarySearch(a, 0, (int)a.size() - 1, b[index]);
//             a.insert(a.begin() + pos, b[index]);
//             processed.insert(index);

//             // insertionDebug("MAIN LOOP", ORANGE, jacobsthal, i, a, b, index, pos, 0); // TESTS
//             // printTests(a, b, "INSERTION TESTS"); // TESTS

//             offset = 1;
//             for (int j = index - 1; j > prevIndex; j--)
//             {
//                 // if (processed.find(j) != processed.end())
//                 //     continue;
//                 pos = binarySearch(a, 0, (int)a.size() - 1 - offset, b[j]);
//                 a.insert(a.begin() + pos, b[j]);
//                 processed.insert(j);
//                 offset++;
       
//             // insertionDebug("REVERSE LOOP", RED, jacobsthal, i, a, b, j, pos, offset); // TESTS
//             // printTests(a, b, "INSERTION TESTS"); // TESTS
//             // std::cout << MAUVE << "OFFSET TEST: " << b[j] + offset << RESET << std::endl;
//             }
//             prevIndex = index;
//         }
//     }
// }


static void insertion(std::vector<int> &a, std::vector<int> &b, int start, int end)
{
    std::vector<int>    jacobsthal = generateJacobsthal(b.size());
    std::set<int>       processed;
    int                 offset;
    int                 index;
    int                 pos;
    int                 prevIndex = 1;

    if (start == 0 && end == static_cast<int>(a.size()) - 1)
    {
        for (int i = 0; i < 2; i++)
        {
            pos = binarySearch(a, 0, (int)a.size() - 1, b[i]);
            a.insert(a.begin() + pos, b[i]);
            processed.insert(i);
        }
        for (int i = 3; i < (int)jacobsthal.size() - 1; i++)
        {
            offset = 0;
            index = jacobsthal[i];
            if (index >= (int)b.size())
                index = b.size() - 1;
            for (int j = index; j > prevIndex; j--)
            {
                // if (processed.find(j) != processed.end())
                //     continue;
                pos = binarySearch(a, 0, (int)a.size() - 1 - offset, b[j]);
                a.insert(a.begin() + pos, b[j]);
                processed.insert(j);
                offset++;
       
            insertionDebug("REVERSE LOOP", RED, jacobsthal, i, a, b, j, pos, offset); // TESTS
            printTests(a, b, "INSERTION TESTS"); // TESTS
            }
            prevIndex = index;
        }
    }
}

static void mergeInsertion(std::vector<int> &a, std::vector<int> &b, int start, int end)
{
    if (start >= end)
        return ;

    int mid = start + (end - start) / 2;
    mergeInsertion(a, b, start, mid);
    mergeInsertion(a, b, mid + 1, end);

    merge(a, b, start, mid, end);
    insertion(a, b, start, end);
}

void PmergeMe::sortVector()
{
    unsigned int n = this->_vec.size();
    int odd = n % 2;
    std::vector<int>    a;
    std::vector<int>    b;

    for (std::vector<int>::iterator it = this->_vec.begin(); it < (this->_vec.end() - odd); (it += 2))
    {
        a.push_back(std::max(*it, *(it + 1)));
        b.push_back(std::min(*it, *(it + 1)));
    }
    if (odd)
        b.push_back(*(this->_vec.rbegin()));
    mergeInsertion(a, b, 0, (n - 1 - odd) / 2);
    this->_vec = a;
}


/*
TODO : handle time + implement algo for std::deque
? use main vector as main chain
*/
