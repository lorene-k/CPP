/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:07:00 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 13:12:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/************************************************** Constructors & destructor */
Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(std::string const &idea)
{
    std::cout << "Brain parameterized constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = idea;
}

Brain::Brain(Brain const &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator overload called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
