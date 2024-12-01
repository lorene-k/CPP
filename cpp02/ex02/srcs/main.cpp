/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:09:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/29 14:32:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void)
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
    
//     std::cout << b << std::endl;
    
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return (0);
// }

// ************************************************************************** //
// static void testConstructorsAndConversion()
// {
//     std::cout << CYAN << "\nConstructor and Conversion Tests:" << std::endl;
//     Fixed a; // Default constructor
//     Fixed b(42); // Int constructor
//     Fixed c(42.42f); // Float constructor
//     Fixed d(b); // Copy constructor

//     std::cout << RESET << "Default: " << a << std::endl;
//     std::cout << "Int(42): " << b << std::endl;
//     std::cout << "Float(42.42f): " << c << std::endl;
//     std::cout << "Copy of Int(42): " << d << std::endl;

//     std::cout << "Int to Float: " << b.toFloat() << std::endl;
//     std::cout << "Float to Int: " << c.toInt() << std::endl;
//     std::cout << std::endl;
// }

// static void testComparisonOperators()
// {
//     std::cout << CYAN << "Comparison Operator Tests:" << std::endl;
//     Fixed a(42);
//     Fixed b(43.5f);

//     std::cout << BLUE << "TRUE = 1; FALSE = 0" << std::endl;
//     std::cout << "a = " << a << "; b = " << b << std::endl;
//     std::cout << RESET << "a > b : "<< (a > b) << std::endl;
//     std::cout << "a < b : "<< (a < b) << std::endl;
//     std::cout << "a >= b : "<< (a >= b) << std::endl;
//     std::cout << "a <= b : "<< (a <= b) << std::endl;
//     std::cout << "a == b : "<< (a == b) << std::endl;
//     std::cout << "a != b : "<< (a != b) << std::endl;
//     std::cout << std::endl;
// }

// static void testArithmeticOperators()
// {
//     std::cout << CYAN << "Arithmetic Operator Tests:" << std::endl;
//     Fixed a(10);
//     Fixed b(2);

//     std::cout << BLUE << "a = " << a << "; b = " << b << std::endl;
//     std::cout << RESET << "a + b = " << (a + b) << std::endl;
//     std::cout << "a - b = " << (a - b) << std::endl;
//     std::cout << "a * b = " << (a * b) << std::endl;
//     std::cout << "a / b = " << (a / b) << std::endl;
//     std::cout << std::endl;
// }

// static void testIncrementDecrement()
// {
//     std::cout << CYAN << "Increment and Decrement Tests:" << std::endl;
//     Fixed a;

//     std::cout << BLUE << "a = " << a << std::endl;
//     std::cout << RESET << "Post-increment: " << a++ << std::endl;
//     std::cout << "After post-increment: " << a << std::endl;
//     std::cout << "Pre-increment: " << ++a << std::endl;
//     std::cout << "After pre-increment: " << a << std::endl;

//     std::cout << "Post-decrement: " << a-- << std::endl;
//     std::cout << "After post-decrement: " << a << std::endl;
//     std::cout << "Pre-decrement: " << --a << std::endl;
//     std::cout << "After pre-decrement: " << a << std::endl;
//     std::cout << std::endl;
// }

// static void testMinMaxFunctions()
// {
//     std::cout << CYAN << "Min/Max Function Tests:" << std::endl;
//     Fixed a(5);
//     Fixed b(10);

//     std::cout << BLUE << "a = " << a << "; b = " << b << std::endl;
//     std::cout << RESET << "Min = " << Fixed::min(a, b) << std::endl;
//     std::cout << "Max: " << Fixed::max(a, b) << std::endl;

//     const Fixed c(15);
//     const Fixed d(20);
    
//     std::cout << BLUE << "c = " << c << "; d = " << d << std::endl;
//     std::cout << RESET << "Const Min = " << Fixed::min(c, d) << std::endl;
//     std::cout << "Const Max = " << Fixed::max(c, d) << std::endl;
//     std::cout << std::endl;
// }

// int main()
// {
//     testConstructorsAndConversion();
//     testComparisonOperators();
//     testArithmeticOperators();
//     testIncrementDecrement();
//     testMinMaxFunctions();
//     return 0;
// }
