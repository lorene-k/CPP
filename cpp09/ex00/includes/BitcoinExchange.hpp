/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2025/01/05 16:20:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP

# define BITCOINEXCHANGE_HPP

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
# include <fstream>
# include <sstream>
# include <string>
# include <algorithm>
# include <map>

class BitcoinExchange
{
private:
    std::string                     _databasePath;
    std::map<std::string, float>    _exchangeRates;

public:
    BitcoinExchange();
    BitcoinExchange(std::string const &databasePath);
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &src);
    ~BitcoinExchange();

    void loadData(std::string const &databasePath);
    std::pair<std::string, float> parseData(std::string const &date) const;
    void printData() const;
};

#endif // *********************************************** BITCOINEXCHANGE_HPP //
