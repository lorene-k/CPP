/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:10:29 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/09 20:07:46 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/********************************************************** WrongAnimal tests */
// int main()
// {
//     const WrongAnimal* random = new WrongAnimal();
//     const WrongAnimal* cat = new WrongCat();
    
//     std::cout << cat->getType() << " " << std::endl;
//     cat->makeSound(); //will not output the cat sound!
//     std::cout << random->getType() << " " << std::endl;
//     random->makeSound();
    
//     delete cat;
//     delete random;
//     return (0);
// }

/************************************************************** Subject tests */
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    return (0);
}
