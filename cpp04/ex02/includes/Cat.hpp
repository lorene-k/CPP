/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:17:42 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 12:59:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP

# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class   Cat : public Animal
{
private:
        Brain *_brain;

public:
        Cat();
        Cat(std::string const &type);
        Cat(Cat const &copy);
        Cat &operator=(const Cat &other);
        ~Cat();

        std::string const &getType(void) const;
	void setType(std::string const &type);
        void makeSound() const; 
};

#endif // *****************************************************  //
