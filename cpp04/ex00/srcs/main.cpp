/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:10:29 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/13 16:14:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/************************************************************ Functions tests */
// int main()
// {
//     std::cout << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
//     Animal* animal = new Animal();
//     Animal* dog = new Dog();
//     Animal* cat = new Cat();
//     WrongAnimal* wrong_animal = new WrongAnimal();
//     WrongAnimal* wrong_cat = new WrongCat();
//     WrongCat* wrong_cat2 = new WrongCat();
    
//     std::cout << std::endl << CYAN << "===== Type Tests =====" << RESET << std::endl;
//     std::cout << "animal type = " << animal->getType() << " " << std::endl;
//     std::cout << "dog type = " << dog->getType() << " " << std::endl;
//     std::cout << "cat type = " << cat->getType() << " " << std::endl;
//     std::cout << "wrong animal type = " << wrong_animal->getType() << " " << std::endl;
//     std::cout << "wrong cat type = " << wrong_cat->getType() << " " << std::endl;
    
//     std::cout << std::endl << CYAN << "===== Sound Tests =====" << RESET << std::endl;
//     std::cout << "animal sound = ";
//     animal->makeSound();
//     std::cout << "dog sound = ";
//     dog->makeSound();
//     std::cout << "cat sound = ";
//     cat->makeSound();
//     std::cout << "wrong animal sound = ";
//     wrong_animal->makeSound();
//     std::cout << "wrong cat sound = ";
//     wrong_cat->makeSound();
//     std::cout << "wrong cat2 sound = ";
//     wrong_cat2->makeSound();
    
//     std::cout << std::endl << CYAN << "===== Destructor Tests =====" << RESET << std::endl;
//     delete animal;
//     delete dog;
//     delete cat;
//     delete wrong_animal;
//     delete wrong_cat;
//     delete wrong_cat2;
//     return (0);
// }

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
