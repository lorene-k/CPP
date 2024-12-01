/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:03:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/02 14:03:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>

class   Contact
{
private:
        std::string     _first_name;
        std::string     _last_name;
        std::string     _nickname;
        std::string     _phone_number;
        std::string     _darkest_secret;

public:
        Contact();
        ~Contact();

        std::string     get_first_name(void) const;
        std::string     get_last_name (void) const;
        std::string     get_nickname (void) const;
        std::string     get_phone_number (void) const;
        std::string     get_darkest_secret (void) const;

        void            set_first_name(std::string input);
        void            set_last_name(std::string input);
        void            set_nickname(std::string input);
        void            set_phone_number(std::string input);
        void            set_darkest_secret(std::string input);
};

#endif // ****************************************************** CONTACT_HPP //