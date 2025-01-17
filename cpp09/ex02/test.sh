#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <Random sequence size>"
    exit 1
fi

SIZE=$1
CC="c++ -Wall -Wextra -Werror -std=c++98"
CHECK="check"
SORT="PmergeMe"
RED="\033[0;31m"
GREEN="\033[0;32m"
RESET="\033[0m"
# GEN="generate"

# make
# ${CC} -o ${GEN} tests/generate.cpp
# ${CC} -o ${CHECK} tests/checkSorted.cpp

echo -e "______________________________________________________________________\n"
echo -e "* Generating random sequence of size $SIZE *"
shuf -i 1-100000 -n $SIZE | tr "\n" " " > numbers.txt

UNSORTED_SEQUENCE=$(cat numbers.txt)

echo "* Sorting using PmergeMe *"
OUTPUT=$(./PmergeMe $UNSORTED_SEQUENCE)

echo -e "\n* PmergeMe output *$OUTPUT"

echo -e "\n* Checking output using checkSort *"
RESULT=$(./$CHECK "$OUTPUT")

echo -e "$RESULT"
echo -e "______________________________________________________________________\n"

rm numbers.txt
# make fclean
# rm "generate"
# rm "check"
# echo -e "${RED}Cleaned generate & check executables${RESET}"