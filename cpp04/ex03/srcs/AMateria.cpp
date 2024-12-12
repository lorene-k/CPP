#include "AMateria.hpp"

/************************************************** Constructors & destructor */
AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &name)
{
    std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
    // Copy member variables here
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    if (this != &other)
    {
        // Copy member variables here
    }
    std::cout << "AMateria copy assignment operator overload called" << std::endl;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << RESET << "AMateria destructor called" << std::endl;
}

/************************************************************* Public methods */

