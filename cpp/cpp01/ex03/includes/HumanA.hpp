/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/03 17:15:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
        std::string _name;
        Weapon      &_weapon;

public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);
        void    setWeapon(Weapon &weapon);
};

#endif // **************************************************** HUMANA_HPP //