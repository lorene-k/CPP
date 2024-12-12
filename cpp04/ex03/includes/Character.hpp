/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:48:51 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 17:40:46 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP

# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria    *_materias[4];

public:
    Character();
    Character(std::string const &name);
    Character(Character const &other);
    Character &operator=(Character const &other);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif // ***************************************************** CHARACTER_HPP //