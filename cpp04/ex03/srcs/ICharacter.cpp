#include "ICharacter.hpp"

/************************************************** Constructors & destructor */
ICharacter::ICharacter()
{
    std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(std::string const &name)
{
    std::cout << "ICharacter parameterized constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &other)
{
    // Copy member variables here
    std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter &ICharacter::operator=(ICharacter const &other)
{
    if (this != &other)
    {
        // Copy member variables here
    }
    std::cout << "ICharacter copy assignment operator overload called" << std::endl;
    return (*this);
}

ICharacter::~ICharacter()
{
    std::cout << RESET << "ICharacter destructor called" << std::endl;
}

/************************************************************* Public methods */

