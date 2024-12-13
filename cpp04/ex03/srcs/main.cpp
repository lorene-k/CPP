/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:12:17 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/13 16:20:04 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/************************************************************* Complete tests */
// int main()
// {
//     std::cout << std::endl << CYAN << "===== Learn Materia Tests =====" << RESET << std::endl;
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     src->learnMateria(new Ice());
//     src->learnMateria(NULL);

//     std::cout << std::endl << CYAN << "===== Create & Equip Materia Tests =====" << RESET << std::endl;
//     ICharacter* me = new Character("me");
//     ICharacter* bob = new Character("bob");

//     AMateria* tmpIce;
//     AMateria* tmpCure;
//     tmpIce = src->createMateria("ice");
//     tmpCure = src->createMateria("cure");
//     me->equip(tmpIce);
//     me->equip(tmpCure);
//     me->equip(NULL);

//     std::cout << std::endl << CYAN << "===== Use Materia Tests =====" << RESET << std::endl;
//     me->use(0, *bob);
//     me->use(1, *bob);
//     me->use(5, *bob);
    
//     std::cout << std::endl << CYAN << "===== Unequip Materia Tests =====" << RESET << std::endl;
//     AMateria* unequippedMateria = tmpIce;
//     me->unequip(0);
//     me->unequip(4);
//     if (unequippedMateria)
//         delete unequippedMateria;
    
//     me->use(0, *bob);

//     delete bob;
//     delete me;
//     delete src;
    
//     return (0);
// }

/************************************************************** Subject tests */
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    return (0);
}
