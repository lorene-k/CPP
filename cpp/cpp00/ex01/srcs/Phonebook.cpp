/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:06:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/02 17:59:24 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->_index = 0;
    std::cout << "\n\t Phonebook empty : add up to 8 contacts\n\n";
}

Phonebook::~Phonebook(void)
{
    std::cout << std::endl << "\t Phonebook closed : all contacts deleted\n\n";
}

/******************************* ADD *****************************************/
void Phonebook::add_contact(void)
{
    std::string input;
    
    std::cout << "\nEnter contact information :\n";
    while (!std::cin.eof() && input == "")
    {
        std::cout << "First name> ";
        if (std::getline(std::cin, input) && input != "")
            this->_contacts[this->_index].set_first_name(input);
    }
    input = "";
    while (!std::cin.eof() && input == "")
    {
        std::cout << "Last name> ";
        if (std::getline(std::cin, input) && input != "")
            this->_contacts[this->_index].set_last_name(input);
    }
    input = "";
    while (!std::cin.eof() && input == "")
    {
        std::cout << "Nickname> ";
        if (std::getline(std::cin, input) && input != "")
            this->_contacts[this->_index].set_nickname(input);
    }
    input = "";
    while (!std::cin.eof() && input == "")
    {
        std::cout << "Phone number> ";
        if (std::getline(std::cin, input) && input != "")
            this->_contacts[this->_index].set_phone_number(input);
    }
    input = "";
    while (!std::cin.eof() && input == "")
    {
        std::cout << "Darkest secret> ";
        if (std::getline(std::cin, input) && input != "")
            this->_contacts[this->_index].set_darkest_secret(input);
    }
    input = "";
    std::cout << "Contact saved in phonebook.\n\n";
    if (this->_index == 7) //handle 9th contact
        this->_index = 0; //display message ? //TEST
    else
        this->_index += 1;
}

/******************************* SEARCH **************************************/
void Phonebook::search_contact(void)
{
    std::string input;
    
    std::cout << "\nSearch contact :\n";
    if (display_book(this->_contacts) == -1)
    {   
        std::cout << "\nEmpty Phonebook : add contacts\n\n";
        return ;
    }
    while (!std::cin.eof())
    {
        std::cout << "Enter contact index> ";
        if (std::getline(std::cin, input) && input != "")
        {
            if (input.size() == 1 && (input[0] >= '1' && input[0] <= '8')
                && this->_contacts[input[0] - 1 - '0'].get_first_name() != "")
                break ;
        }
        if (this->_contacts[input[0] - 1 - '0'].get_first_name() == ""
            && input.size() == 1 && (input[0] >= '1' && input[0] <= '8'))
            std::cout << "Contact doesn't exist\n\n";
        else if (input != "")
            std::cout << "Invalid index! ";
    }
    this->display_contact(this->_contacts[input[0] - 1 - '0']);
}

/*********************************** DISPLAY *********************************/
void Phonebook::display_contact(Contact contact)
{
    std::cout << "\nContact info :" << std::endl;
    std::cout << "First name: " << contact.get_first_name() << std::endl;
    std::cout << "Last name: " << contact.get_last_name() << std::endl;
    std::cout << "Nickname: " << contact.get_nickname() << std::endl;
    std::cout << "Phone number: " << contact.get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contact.get_darkest_secret() << "\n\n";
}

/*********************************** UTILS ***********************************/
std::string check_len(std::string str)
{
    if (str.size() > 10)
    {
        str.resize(10);
        str.replace(9, 1, ".");
    }
    return (str);
}

std::string check_spaces(size_t n)
{
    std::string str;

    str.reserve(n);
    while (n--)
        str.append(" ");
    return (str);
}

int         display_book(Contact contacts[8])
{
    int         i;
    std::string str;
    
    i = -1;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
    while (contacts[i + 1].get_first_name() != "" && (++i < 8))
    {
        str = i + 1 + '0';
        std::cout << "|" << check_spaces(10 - str.size()) << str << "|";
        str = check_len(contacts[i].get_first_name());
        std::cout << check_spaces(10 - str.size()) << str << "|";
        str = check_len(contacts[i].get_last_name());
        std::cout << check_spaces(10 - str.size()) << str << "|";
        str = check_len(contacts[i].get_nickname());
        std::cout << check_spaces(10 - str.size()) << str << "|" << std::endl;
        break ;
    }
    return (i);
}
