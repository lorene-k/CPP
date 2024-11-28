/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:54:50 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/25 19:49:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
    // std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{
    // std::cout << "Copy constuctor called" << std::endl;
}

Point &Point::operator=(const Point &)
{
    // std::cout << "Copy assignment operator called - disabled for Point objects due to const members." << std::endl;
    return (*this);
}

Point::~Point()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}