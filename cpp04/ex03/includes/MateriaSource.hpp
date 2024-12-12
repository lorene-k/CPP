/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:51:15 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/12 18:13:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP

# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materias[4];

public:
    MateriaSource();
    MateriaSource(AMateria *materia[4]);
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);
    ~MateriaSource();

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif // ************************************************* MATERIASOURCE_HPP //