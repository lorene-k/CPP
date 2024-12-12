#include "IMateriaSource.hpp"

/************************************************** Constructors & destructor */
IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(std::string const &name)
{
    std::cout << "IMateriaSource parameterized constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &other)
{
    // Copy member variables here
    std::cout << "IMateriaSource copy constructor called" << std::endl;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other)
{
    if (this != &other)
    {
        // Copy member variables here
    }
    std::cout << "IMateriaSource copy assignment operator overload called" << std::endl;
    return (*this);
}

IMateriaSource::~IMateriaSource()
{
    std::cout << RESET << "IMateriaSource destructor called" << std::endl;
}

/************************************************************* Public methods */

