/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 17:23:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP

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
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <sstream>
# include <cmath>

enum e_type
{
    PSEUDO,
    CHAR,
    INT,
    DOUBLE,
    FLOAT
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(std::string const &);
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);
    ~ScalarConverter();

public:
    static void convert(std::string &literal);
};

int detectType(std::string &literal);
void display(std::string &literal, int type);

#endif // *********************************************** SCALARCONVERTER_HPP //