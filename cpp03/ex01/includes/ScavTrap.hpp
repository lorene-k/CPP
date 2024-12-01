/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:32:19 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/29 17:11:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &scavTrap);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        
        void attack(const std::string& target);
        void guardGate();
};

#endif // ***************************************************** SCAVTRAP_HPP //