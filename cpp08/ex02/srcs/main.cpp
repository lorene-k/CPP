/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/01 19:43:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// *********************************************************** TEST FUNCTIONS //
static void listTest(void)
{
    std::cout << std::endl << CYAN << "===== LIST TESTS =====" << RESET << std::endl;
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << list.back() << std::endl;

    list.pop_back();

    std::cout << list.size() << std::endl;

    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator  it = list.begin();
    std::list<int>::iterator ite = list.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}


static void mstackSubjectTest(void)
{
    std::cout << std::endl << CYAN << "===== MUTANT STACK SUBJECT TESTS =====" << RESET << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

// ****************************************************************** MY MAIN //
int main (void)
{
    mstackSubjectTest();
    listTest();
    
    std::cout << std::endl;
    return (0);
}
