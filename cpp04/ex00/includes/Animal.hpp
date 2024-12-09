/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:09:33 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/09 19:18:56 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define CYAN    "\033[0;36m"
# define RESET   "\033[0m"
# define ORANGE  "\033[0;38;5;208m"
# define PURPLE  "\033[0;35m"

# include <iostream>
# include <string>

class   Animal
{
protected:
        std::string _type;

public:
        Animal();
        Animal(std::string const &type);
        Animal(Animal const &copy);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        std::string const &getType() const;
        void setType(std::string const &type);
        virtual void makeSound() const;
};

#endif // *******************************************************  ANIMAL_HPP//
