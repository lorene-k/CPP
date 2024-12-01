/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/22 13:51:38 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>

class   Weapon
{
private:
        std::string     _type;

public:
        Weapon(std::string type);
        ~Weapon(void);
        const   std::string& getType() const;
        void    setType(std::string type);
};

#endif // **************************************************** WEAPON_HPP //