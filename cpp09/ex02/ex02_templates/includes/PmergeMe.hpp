/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/17 16:10:36 by lkhalifa         ###   ########.fr       */
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

template <typename T>
int BinarySearch(T &a, int start, int end, int key)
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

template <typename T>
void Insertion(T &a, T &b, int start, int end)
{
    T    jacobsthal = generateJacobsthal<T>(b.size() + 1);
    std::set<int>       processed;
    int                 offset;
    int                 index;
    int                 pos;
    int                 prevIndex = 1;

    if (start == 0 && end == static_cast<int>(a.size()) - 1)
    {
        for (int i = 0; i < 2; i++)
        {
            pos = BinarySearch(a, 0, (int)a.size() - 1, b[i]);
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
                pos = BinarySearch(a, 0, (int)a.size() - 1 - offset, b[j]);
                a.insert(a.begin() + pos, b[j]);
                processed.insert(j);
                offset++;
            }
            if (processed.size() == b.size())
                break;
            prevIndex = index;
        }
    }
}

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
void MergeInsertion(T &a, T &b, int start, int end)
{
    if (start >= end)
        return ;

    int mid = start + (end - start) / 2;
    MergeInsertion(a, b, start, mid);
    MergeInsertion(a, b, mid + 1, end);
    merge(a, b, start, mid, end);
    Insertion(a, b, start, end);
}

/* ************************************************************************** */
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
                throw std::runtime_error("duplicate");
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
    
    template <typename T>
    void sort(T &cont)
    {
    unsigned int n = cont.size();
    int odd = n % 2;
    T    a;
    T    b;

    if (checkSize(cont, n))
        return ;
    for (typename T::iterator it = cont.begin(); it < (cont.end() - odd); (it += 2))
    {
        a.push_back(std::max(*it, *(it + 1)));
        b.push_back(std::min(*it, *(it + 1)));
    }
    if (odd)
        b.push_back(*(cont.rbegin()));
    MergeInsertion(a, b, 0, (n - 1 - odd) / 2);
    cont = a;
    }
};

#endif // *********************************************************** PMERGEME_HPP //
