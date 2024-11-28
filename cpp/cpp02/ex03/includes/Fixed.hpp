/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/25 21:16:22 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class   Fixed
{
private:
        int _value;
        static const int _fractionalBits = 8;

public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);

        /* EX01 */
        Fixed(const int value);
        Fixed(const float value);
        float toFloat(void) const;
        int toInt(void) const;

        /* EX02 */
        // Comparison operators
        bool operator>(const Fixed &comparedTo) const;
        bool operator<(const Fixed &comparedTo) const;
        bool operator>=(const Fixed &comparedTo) const;
        bool operator<=(const Fixed &comparedTo) const;
        bool operator==(const Fixed &comparedTo) const;
        bool operator!=(const Fixed &comparedTo) const;

        // Arithmetic operators
        Fixed operator+(const Fixed &operand) const;
        Fixed operator-(const Fixed &operand) const;
        Fixed operator*(const Fixed &operand) const;
        Fixed operator/(const Fixed &operand) const;
        
        // Increment/decrement operators
        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int n);
        Fixed operator--(int n);

        // Overloaded functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // ******************************************************** FIXED_HPP //