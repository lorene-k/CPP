/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:51:23 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 13:09:03 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
        std::string _ideas[100];

public:
        Brain();
        Brain(std::string const &idea);
        Brain(Brain const &other);
        Brain &operator=(Brain const &other);
        ~Brain();
};

#endif // ********************************************************* BRAIN_HPP //

