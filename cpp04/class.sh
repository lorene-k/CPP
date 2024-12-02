#!/bin/bash

# Check if arguments are provided
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <ClassName> <Path to Directory>"
    exit 1
fi

CLASS_NAME=$1
UPPER_CLASS_NAME=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]') # Uppercase class name for include guards
OUTPUT_PATH=$2

# Generate .cpp file
cat << EOF >> "$CLASS_NAME.cpp"
#include "${CLASS_NAME}.hpp"

/************************************************* Constructors & destructor */
$CLASS_NAME::$CLASS_NAME()
{
    std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

$CLASS_NAME::$CLASS_NAME() :
{
    std::cout << "$CLASS_NAME parameterized constructor called" << std::endl;
}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &other)
{
    std::cout << "$CLASS_NAME copy constructor called" << std::endl;
    *this = other;
}

$CLASS_NAME & $CLASS_NAME::operator=(const $CLASS_NAME &other)
{
    std::cout << "$CLASS_NAME copy assignment operator overload called" << std::endl;
    if (this != &other) {
        // Copy member variables here
    }
    return *this;
}

$CLASS_NAME::~$CLASS_NAME() {
    std::cout << RESET << "$CLASS_NAME destructor called" << std::endl;
}

/************************************************************ Public methods */

EOF

# Generate .hpp file
cat << EOF >> "$CLASS_NAME.hpp"

#ifndef ${UPPER_CLASS_NAME}_HPP

# define ${UPPER_CLASS_NAME}_HPP

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

class $CLASS_NAME
{
protected:


public:
    $CLASS_NAME();
    $CLASS_NAME(std::string name);
    $CLASS_NAME(const $CLASS_NAME &copy);
    $CLASS_NAME &operator=(const $CLASS_NAME &other);
    ~$CLASS_NAME();
};

#endif // ***************************************************** ${UPPER_CLASS_NAME}_HPP //
EOF

# Move files to the specified directory
mv "$CLASS_NAME.cpp" "$OUTPUT_PATH/srcs"
mv "$CLASS_NAME.hpp" "$OUTPUT_PATH/includes"

echo "Files $CLASS_NAME.cpp and $CLASS_NAME.hpp generated and moved to $OUTPUT_PATH."
