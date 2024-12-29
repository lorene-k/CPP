/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 18:16:52 by lkhalifa         ###   ########.fr       */
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
# include <cstdlib>

template <typename T>
class Array
{
private:
        T               *_array;
        unsigned int    _n;

public:
    Array<T>();
    Array<T>(unsigned int n);
    Array<T>(Array<T> const &src);
    Array<T> &operator=(Array<T> const &src);
    ~Array<T>();

    T &operator[](unsigned int i);
    unsigned int size() const;
};

#include "Array.tpp"

#endif // ********************************************************* ARRAY_HPP //