/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/27 17:19:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP

# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0), _array(new T[0]) //or _array(nullptr) ??
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _n(n)
{
    std::cout << "Array parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(Array<T> const &src) : _n(src.size()), _array(new T[src.size()])
{
    for (unsigned int i = 0; i < src.size(); i++)
        this->_array[i] = src._array[i];
    std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &src)
{
    if (this != &src)
    {
        delete[] this->_array;
        this->_array = new T[src.size()];
        this->_n = src.size();
        for (unsigned int i = 0; i < src.size(); i++)
            this->_array[i] = src._array[i];
    }
    std::cout << "Array copy assignment operator called" << std::endl;
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->size())
        throw std::out_of_range("Index out of range"); // check msg
    return (this->_array[i]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_array;
    std::cout << "Array destructor called" << std::endl;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_n);
}

#endif // ********************************************************** ARRAY_TPP //