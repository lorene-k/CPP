/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:04:07 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 17:49:18 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(AMateria const &other);
    AMateria &operator=(AMateria const &other);
    virtual ~AMateria();

    std::string const &getType() const;

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif // ***************************************************** AMATERIA_HPP //