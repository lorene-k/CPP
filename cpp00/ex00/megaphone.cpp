/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:03:19 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/21 17:37:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int     i;
    size_t  j;

    i = 0;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        while (av && av[++i])
        {
            std::string arg(av[i]);
            j = -1;
            while (++j < arg.size())
                std::cout << (char)std::toupper(arg[j]);
        }
    std::cout << std::endl;
    return (0);
}
