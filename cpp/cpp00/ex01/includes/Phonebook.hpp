/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:04:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/11/21 18:32:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

std::string     check_len(std::string str);
int	        	display_book(Contact contacts[8]);

class Phonebook
{
  private:
	Contact _contacts[8];
	int     _index;

  public:
	Phonebook();
	~Phonebook();

	void    add_contact(void);
	void    search_contact(void);
	void    display_contact(Contact contact);
};

#endif // **************************************************** PHONEBOOK_HPP //