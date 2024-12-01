/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/22 13:51:32 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
        std::string     _name;
        Weapon          &_weapon;

public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);
        void    setWeapon(Weapon &weapon);
};

#endif // **************************************************** HUMANA_HPP //