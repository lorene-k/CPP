/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/25 10:14:03 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constuctor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        setRawBits(fixed.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

/********************************************************************** EX01 */

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(value << _fractionalBits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits((int)roundf(value * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return ((int)_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

/********************************************************************** EX02 */

// Comparison operators
bool Fixed::operator>(const Fixed &comparedTo) const
{
    return (this->getRawBits() > comparedTo.getRawBits());
}

bool Fixed::operator<(const Fixed &comparedTo) const
{
    return (this->getRawBits() < comparedTo.getRawBits());
}

bool Fixed::operator>=(const Fixed &comparedTo) const
{
    return (this->getRawBits() >= comparedTo.getRawBits());
}

bool Fixed::operator<=(const Fixed &comparedTo) const
{
    return (this->getRawBits() <= comparedTo.getRawBits());
}

bool Fixed::operator==(const Fixed &comparedTo) const
{
    return (this->getRawBits() == comparedTo.getRawBits());
}

bool Fixed::operator!=(const Fixed &comparedTo) const
{
    return (this->getRawBits() != comparedTo.getRawBits());
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &operand) const
{
    Fixed res(this->toFloat() + operand.toFloat());
    return (res);
}

Fixed Fixed::operator-(const Fixed &operand) const
{
    Fixed res(this->toFloat() - operand.toFloat());
    return (res);
}

Fixed Fixed::operator*(const Fixed &operand) const
{
    Fixed res(this->toFloat() * operand.toFloat());
    return (res);
}

Fixed Fixed::operator/(const Fixed &operand) const
{
    Fixed res(this->toFloat() / operand.toFloat());
    return (res);
}

// Increment/decrement operators
Fixed   &Fixed::operator++(void)
{
    this->_value += 1;
    return (*this);
}

Fixed   &Fixed::operator--(void)
{
    this->_value -= 1;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp;
    
    tmp = *this;
    this->_value += 1;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp;
    
    tmp = *this;
    this->_value -= 1;
    return (tmp);
}

// Overloaded functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}