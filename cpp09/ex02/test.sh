#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <Random sequence size>"
    exit 1
fi

SIZE=$1
CC="c++ -Wall -Wextra -Werror -std=c++98"
GEN="generate"
CHECK="check"
RED="\033[0;31m"
GREEN="\033[0;32m"
RESET="\033[0m"

${CC} -o ${GEN} generate.cpp
${CC} -o ${CHECK} checkSorted.cpp

echo -e "${GREEN}Generating random sequence of size $SIZE${RESET}"
./${GEN} $SIZE

# Make PmergeMe
# Exec PmergeMe with generated random sequence
# Exec check with output to check if sorted

# rm "generate"
# rm "check"