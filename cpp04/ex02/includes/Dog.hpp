/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:33:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 12:59:14 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP

# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class   Dog : public Animal
{
private:
        Brain *_brain;

public:
        Dog();
        Dog(std::string const &type);
        Dog(Dog const &copy);
        Dog &operator=(const Dog &other);
        ~Dog();

        std::string const &getType(void) const;
	void setType(std::string const &type);
        void makeSound() const;
};

#endif // ***************************************************** DOG_HPP //
