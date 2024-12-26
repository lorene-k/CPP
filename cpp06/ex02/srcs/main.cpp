/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/26 16:00:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int     main()
{
    srand(time(NULL));
    Base *base = generate();

    std::cout << MAUVE << "\n===== Pointer-based identify function =====" << RESET << std::endl;
    identify(base);
    std::cout << MAUVE << "\n===== Reference-based identify function =====" << RESET << std::endl;
    identify(*base);
    
    std::cout << std::endl;
    delete base;
    return (0);
}

// CHECK LEAKS