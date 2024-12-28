/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 15:58:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

# define SERIALIZER_HPP

# define RESET  "\033[0m"
# define RED    "\033[0;31m"
# define ORANGE "\033[0;38;5;208m"
# define YELLOW "\033[0;33m"
# define GREEN  "\033[0;32m"
# define BLUE   "\033[0;34m"
# define CYAN   "\033[0;36m"
# define PURPLE "\033[0;35m"
# define MAUVE  "\033[38;5;177m"

# include <iostream>
# include <string>
# include <stdint.h> 

struct Data
{
    int         value;
};

class Serializer
{
private:
    Serializer();
    Serializer(std::string const &);
    Serializer(Serializer const &other);
    Serializer &operator=(Serializer const &other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // **************************************************** SERIALIZER_HPP //