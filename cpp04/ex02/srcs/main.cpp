/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:10:29 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 14:58:44 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/******************************************** Abstract test - won't compile ! */
// int main()
// {
//     Animal animal1;
//     Animal *animal2 = new Animal();
//     delete animal2;
//     return (0);
// }

/************************************************************* Complete tests */
int main()
{
    std::cout << std::endl << CYAN << "===== Constructor Tests =====" << RESET << std::endl;
    const Animal *animals[10];
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << YELLOW << "Dog " << i << " : " << RESET;
        animals[i] = new Dog();
        std::cout << YELLOW << "Cat " << i << " : " << RESET;
        animals[i + 5] = new Cat();
    }
    
    std::cout << std::endl << CYAN << "===== Destructor Tests =====" << RESET << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << YELLOW << "Animal " << i << " : ";
        if (i < 5)
            std::cout << "Dog" << RESET << std::endl;
        else
            std::cout << "Cat" << RESET << std::endl;
        delete animals[i];
    }

    std::cout << std::endl << CYAN << "===== Deep Copy Test =====" << RESET << std::endl;
    const Dog dog;
    const Dog copy = dog;
    
    std::cout << YELLOW << "dog brain address: " << dog.getBrain() << std::endl;
    std::cout << YELLOW << "copy brain address: " << copy.getBrain() << RESET << std::endl;
    return (0);
}

/************************************************************** Subject tests */
// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     delete j;
//     delete i;
    
//     return (0);
// }
