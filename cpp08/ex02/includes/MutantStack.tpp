/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/01 19:33:47 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP

# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

/**************************************************** Orthodox Canonical Form */
template <typename T>
MutantStack<T>::MutantStack()
{
    // std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(std::string const &)
{
    // std::cout << "MutantStack parameterized constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>(src)
{
    // std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &src)
{
    if (this != &src)
		std::stack<T>::operator=(src);
    // std::cout << "MutantStack copy assignment operator called" << std::endl;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    // std::cout << "MutantStack destructor called" << std::endl;
}

/****************************************************************** Iterators */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (std::stack<T>::c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (std::stack<T>::c.cend());
}

/********************************************************** Reverse Iterators */
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (std::stack<T>::c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (std::stack<T>::c.crend());
}

#endif // *************************************************** MUTANTSTACK_TPP //