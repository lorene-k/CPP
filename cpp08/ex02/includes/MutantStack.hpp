/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/01 19:34:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP

# define MUTANTSTACK_HPP

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
# include <list>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>();
    MutantStack<T>(std::string const &);
    MutantStack<T>(MutantStack const &src);
    MutantStack<T> &operator=(MutantStack const &src);
    ~MutantStack<T>();

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif // *************************************************** MUTANTSTACK_HPP //

/*
TESTS
- Ensure that MutantStack retains full compatibility with std::stack, including its member functions like push, pop, top, and empty
- Test the MutantStack class with various STL algorithms (like std::for_each, std::sort, std::find
- Verify that the iterators work correctly and that the stack behaves like a standard std::stack

- run subject test w/ MutantStack
- run subject tests w/ std::list (same output) + vector ?
> when testing another container, update the code with the corresponding member functions (push() can become push_back())
*/


 
/*
Your MutantStack class should mirror the template design of std::stack:

Element Type (T):

This determines the type of elements stored in the MutantStack.
Container Type (Container):

This allows you to specify the type of the underlying container (default: std::deque).

>> template <typename T, typename Container>
*/