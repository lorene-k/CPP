/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/27 16:55:56 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

# define ARRAY_HPP

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
# include <iomanip>

template <typename T>
class Array
{
private:
        T               *_array;
        unsigned int    _n;

public:
    Array<T>() : _n(0), _array(new T[0]) //or _array(nullptr) ??
    {
        std::cout << "Array default constructor called" << std::endl;
    }
    
    Array<T>(unsigned int n) : _n(n), _array(new T[n])
    {
        std::cout << "Array parameterized constructor called" << std::endl;
    }

    Array<T>(Array<T> const &src) : _n(src.size()), _array(new T[src.size()])
    {
        for (unsigned int i = 0; i < src.size(); i++)
            this->_array[i] = src._array[i];
        std::cout << "Array copy constructor called" << std::endl;
    }

    Array<T> &operator=(Array<T> const &src)
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

    T &operator[](unsigned int i)
    {
        if (i >= this->size())
            throw std::out_of_range("Index out of range"); // check msg
        return (this->_array[i]);
    }
    
    ~Array<T>()
    {
        delete[] this->_array;
        std::cout << "Array destructor called" << std::endl;
    }

    unsigned int size() const
    {
        return (this->_n);
    }
};

#endif // ********************************************************** ARRAY_HPP //