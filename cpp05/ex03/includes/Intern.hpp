/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:16:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/19 15:23:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP

# define INTERN_HPP

# include "AForm.hpp"

class Aform;

class Intern
{
public:
    Intern();
    Intern(std::string const &msg);
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();

    AForm *makeForm(std::string const &name, std::string const &target);
};

#endif // ***************************************************** INTERN_HPP //