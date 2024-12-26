/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:58:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/26 15:58:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base    *generate(void)
{
    int i = rand() % 3;
    switch (i)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (NULL);
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    try 
    {
        A &a =dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e) {}
    try 
    {
        B &b =dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e) {}   
    try 
    {
        C &c =dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e) {}   
}
