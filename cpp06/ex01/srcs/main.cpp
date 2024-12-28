/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/28 16:03:23 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void printData(Data* data)
{
    std::cout << "Data value: " << data->value << std::endl;
    std::cout << "Data address: " << data << std::endl << std::endl;
}

int main()
{
    Data *data = new Data;
    data->value = 42;

    std::cout << CYAN << "\n===== Original data value =====" << RESET << std::endl;
    printData(data);
    
    uintptr_t raw = Serializer::serialize(data);
    data = Serializer::deserialize(raw);
    
    std::cout << CYAN << "===== After serialize =====" << RESET << std::endl;
    std::cout << "Raw value: " << raw << std::endl << std::endl;
    std::cout << CYAN << "===== After deserialize =====" << RESET << std::endl;
    printData(data);

    delete data;
    return (0);
}
