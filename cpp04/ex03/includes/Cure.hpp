/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:41:19 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 18:41:10 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP

# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(std::string const &type);
    Cure(Cure const &other);
    Cure &operator=(Cure const &other);
    virtual ~Cure();

    Cure *clone() const;
    void use(ICharacter& target);
};

#endif // ********************************************************** CURE_HPP //