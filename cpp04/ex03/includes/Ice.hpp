/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:41:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 17:34:12 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP

# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(std::string const &type);
    Ice(Ice const &other);
    Ice &operator=(Ice const &other);
    virtual ~Ice();

    Ice *clone() const;
    void use(ICharacter& target);
};

#endif // *********************************************************** ICE_HPP //