#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <Random sequence size>"
    exit 1
fi

SIZE=$1
CC="c++ -Wall -Wextra -Werror -std=c++98"
GEN="generate"
CHECK="check"
SORT="PmergeMe"
RED="\033[0;31m"
GREEN="\033[0;32m"
RESET="\033[0m"

# make
# ${CC} -o ${GEN} tests/generate.cpp
# ${CC} -o ${CHECK} tests/checkSorted.cpp

echo -e "______________________________________________________________________\n"
echo -e "* Generating random sequence of size $SIZE *"
./${GEN} $SIZE > numbers.txt

if [ $? -ne 0 ]; then
  echo "Error: generate failed to execute properly." >&2
  exit 1
fi

UNSORTED_SEQUENCE=$(cat numbers.txt | tr '\n' ' ')

echo "* Sorting using PmergeMe *"
OUTPUT=$(./PmergeMe $UNSORTED_SEQUENCE)

echo -e "\n* PmergeMe output *$OUTPUT"

# echo -e "\n* Checking the sort result using checkSort *"
# RESULT=$(./$CHECK "$OUTPUT")

echo -e "$RESULT"
echo -e "______________________________________________________________________\n"

# make fclean
# rm "generate"
# rm "check"
# echo -e "${RED}Cleaned generate & check executables${RESET}"