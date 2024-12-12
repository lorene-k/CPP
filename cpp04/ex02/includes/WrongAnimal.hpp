/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:09:33 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/09 19:22:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

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

class   WrongAnimal
{
protected:
        std::string _type;

public:
        WrongAnimal();
        WrongAnimal(std::string const &name);
        WrongAnimal(WrongAnimal const &copy);
        WrongAnimal &operator=(WrongAnimal const &other);
        virtual ~WrongAnimal();

        std::string const &getType() const;
        void setType(std::string const &type);
        void makeSound() const;
};

#endif // ****************************************************  WRONGANIMAL_HPP//
