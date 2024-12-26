/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/26 23:55:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int     main()
{
    std::cout << CYAN << "\n===== INT TESTS =====" << RESET << std::endl;
    int a = 1;
    int b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << PURPLE << "After swap : " << RESET << "a = " << a << ", b = " << b << std::endl;
    std::cout << PURPLE << "Implicit instanciation " << RESET << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << PURPLE << "Explicit instanciation " << RESET << "max( a, b ) = " << ::max<int>(a, b) << std::endl;

    std::cout << CYAN << "\n===== FLOAT TESTS =====" << RESET << std::endl;
    float c = 1.5;
    float d = 2.4;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << PURPLE << "After swap : " << RESET << "c = " << c << ", d = " << d << std::endl;
    std::cout << PURPLE << "Implicit instanciation " << RESET << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << PURPLE << "Explicit instanciation " << RESET << "max( c, d ) = " << ::max<float>(c, d) << std::endl;

    std::cout << CYAN << "\n===== CHAR TESTS =====" << RESET << std::endl;
    char e = 'A';
    char f = 'B';
    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << PURPLE << "After swap : " << RESET << "e = " << e << ", f = " << f << std::endl;
    std::cout << PURPLE << "Implicit instanciation " << RESET << "min( e,f ) = " << ::min(e, f) << std::endl;
    std::cout << PURPLE << "Explicit instanciation " << RESET << "max( e, f ) = " << ::max<char>(e, f) << std::endl;

    std::cout << CYAN << "\n===== STRING TESTS =====" << RESET << std::endl;
    std::string g = "str1";
    std::string h = "str2";
    std::cout << "g = " << g << ", h = " << h << std::endl;
    ::swap(g, h);
    std::cout << PURPLE << "After swap : " << RESET << "g = " << g << ", h = " << h << std::endl;
    std::cout << PURPLE << "Implicit instanciation " << RESET << "min( g, h ) = " << ::min(g, h) << std::endl;
    std::cout << PURPLE << "Explicit instanciation " << RESET << "max( g, h ) = " << ::max<std::string>(g, h) << std::endl <<  std::endl;

    return (0);
}
