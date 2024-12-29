/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/29 15:43:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

# define SPAN_HPP

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
# include <cstdlib>
# include <algorithm>
# include <vector>
# include <numeric>

class Span
{
private:
    unsigned int        _N;
    std::vector<int>    _v;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();

    void    addNumber(int num);
    int     shortestSpan() const;
    int     longestSpan() const;
    void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class FullException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    
    class LessThanTwoException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#endif // ********************************************************** SPAN_HPP //
