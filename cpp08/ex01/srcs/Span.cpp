/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:29:18 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/30 09:59:18 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/************************************************** Constructors & destructor */
Span::Span() : _N(0)
{
    // std::cout << "Span Default Constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    // std::cout << "Span Parameterized Constructor called" << std::endl;
}

Span::Span(const Span &copy) : _N(copy._N), _v(copy._v)
{
    // std::cout << "Span Copy Constructor called" << std::endl;
    *this = copy;
}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_N = copy._N;
        this->_v = copy._v;
    }
    // std::cout << "Span Copy Assignment Operator called" << std::endl;
    return (*this);
}

Span::~Span()
{
    // std::cout << "Span Destructor called" << std::endl;
}

/********************************************************** Exception methods */
const char *Span::FullException::what() const throw()
{
    return ("No elements can be added: Span full");
}

const char *Span::LessThanTwoException::what() const throw()
{
    return ("No span can be found: Less than 2 elements");
}

/************************************************************ Public methods */

void    Span::addNumber(int num)
{
    if (_v.size() == _N)
        throw Span::FullException();
    _v.push_back(num);
}

int     Span::shortestSpan() const
{
    if  (_v.size() < 2)
        throw Span::LessThanTwoException();
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    int span = tmp[1] - tmp[0];
    for (long unsigned int i = 0; i < tmp.size() - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < span)
            span = tmp[i + 1] - tmp[i];
    }
    return (span);
}

int     Span::longestSpan() const
{
    if  (_v.size() < 2)
        throw Span::LessThanTwoException();
    int min = *std::min_element(_v.begin(), _v.end());
    int max = *std::max_element(_v.begin(), _v.end());
    return (max - min);
}

void    Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    unsigned int newSize = std::distance(begin, end) + _v.size();
    if (newSize > _N)
        throw Span::FullException();
    _v.insert(_v.end(), begin, end);
}
