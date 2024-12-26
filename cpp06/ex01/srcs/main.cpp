/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:02:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/12/26 15:06:10 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

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

// TEST LEAKS