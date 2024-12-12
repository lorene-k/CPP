#!/bin/bash

# Check if at least two arguments are provided
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <ClassName> [base] <Path to Directory>"
    exit 1
fi

if [ -z "$3" ]; then
    OUTPUT_PATH=$2
else
    OUTPUT_PATH=$3
fi
CLASS_NAME=$1
UPPER_CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]') # Uppercase class name for include guards
COLOR_DEFINE=false

# Check if the second argument is "base"
if [ ! -z "$2" ] && [ "$2" == "base" ]; then
    COLOR_DEFINE=true
fi

# Generate .cpp file
cat << EOF >> "$CLASS_NAME.cpp"
#include "${CLASS_NAME}.hpp"

/************************************************** Constructors & destructor */
$CLASS_NAME::$CLASS_NAME()
{
    std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

$CLASS_NAME::$CLASS_NAME(std::string const &name)
{
    std::cout << "$CLASS_NAME parameterized constructor called" << std::endl;
}

$CLASS_NAME::$CLASS_NAME($CLASS_NAME const &other)
{
    // Copy member variables here
    std::cout << "$CLASS_NAME copy constructor called" << std::endl;
}

$CLASS_NAME &$CLASS_NAME::operator=($CLASS_NAME const &other)
{
    if (this != &other)
    {
        // Copy member variables here
    }
    std::cout << "$CLASS_NAME copy assignment operator overload called" << std::endl;
    return (*this);
}

$CLASS_NAME::~$CLASS_NAME()
{
    std::cout << RESET << "$CLASS_NAME destructor called" << std::endl;
}

/************************************************************* Public methods */

EOF

# Generate .hpp file
cat << EOF >> "$CLASS_NAME.hpp"
#ifndef ${UPPER_CLASS_NAME}_HPP

# define ${UPPER_CLASS_NAME}_HPP
EOF

# Add color definitions if "base" is provided as the second argument
if $COLOR_DEFINE; then
    cat << EOF >> "$CLASS_NAME.hpp"

# define RED     "\\033[0;31m"
# define GREEN   "\\033[0;32m"
# define YELLOW  "\\033[0;33m"
# define BLUE    "\\033[0;34m"
# define CYAN    "\\033[0;36m"
# define RESET   "\\033[0m"
# define ORANGE  "\\033[0;38;5;208m"
# define PURPLE  "\\033[0;35m"

# include <iostream>
# include <string>
EOF
fi

# Add common includes and class declaration
cat << EOF >> "$CLASS_NAME.hpp"

class $CLASS_NAME
{
protected:


public:
    $CLASS_NAME();
    $CLASS_NAME(std::string const &name);
    $CLASS_NAME($CLASS_NAME const &other);
    $CLASS_NAME &operator=($CLASS_NAME const &other);
    ~$CLASS_NAME();
};

#endif // ***************************************************** ${UPPER_CLASS_NAME}_HPP //

EOF

# Move files to the specified directory
mv "$CLASS_NAME.cpp" "$OUTPUT_PATH/srcs"
mv "$CLASS_NAME.hpp" "$OUTPUT_PATH/includes"

echo "Files $CLASS_NAME.cpp and $CLASS_NAME.hpp generated and moved to $OUTPUT_PATH"
