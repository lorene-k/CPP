/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/09 15:34:59 by lkhalifa         ###   ########.fr       */
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

class PmergeMe
{
private:
    std::vector<int>    _vec;
    std::deque<int>     _deq;
    void                parse(char **av);
    void                sortVector();
    void                sortQueue();
    void                display(char **av, double vTime, double qTime);
    // void                sortStepTwo(unsigned int start, unsigned int end);

public:
    PmergeMe();
    PmergeMe(std::string const &);
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();

    void                process(char **av);
};

#endif // *********************************************************** PMERGEME_HPP //
