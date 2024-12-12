#ifndef AMATERIA_HPP

# define AMATERIA_HPP

# define RED     "\033[0;31m"
# define GREEN   "\033[0;32m"
# define YELLOW  "\033[0;33m"
# define BLUE    "\033[0;34m"
# define CYAN    "\033[0;36m"
# define RESET   "\033[0m"
# define ORANGE  "\033[0;38;5;208m"
# define PURPLE  "\033[0;35m"

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(AMateria const &other);
    AMateria &operator=(AMateria const &other);
    ~AMateria();

    std::string const &getType() const;
    std::string const &setType();

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif // ***************************************************** AMATERIA_HPP //

