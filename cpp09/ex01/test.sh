#!/bin/bash

EXECUTABLE="./RPN"

PASSED_TESTS=0
TOTAL_TESTS=0

RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'

declare -a TESTS=(
    # VALID TESTS
    "3 3 +|6"
    "9 2 -|7"
    "4 2 *|8"
    "8 4 /|2"
    "3 5 + 2 -|6"
    "7 2 3 * +|13"
    "5 1 2 + 4 * + 3 -|14"
    "9 9 9 + +|27"
    "1 2 3 + +|6"
    "4 3 -|1"
    "2 2 * 2 /|2"
    "3 1 + 2 +|6"
    "6 3 * 2 /|9"
    "2 2 3 + *|10"
    "9 8 3 - *|45"
    "3 4 5 + *|27"
    "9 5 3 + *|72"
    "1 1 + 1 *|2"
    "1 1 1 * +|2"
    "2 3 + 2 +|7"
    "3 3 3 3 / / / |1"
    "9 9 9 9 9 - - - - 8 - 4 -|-3"
    "6 6 * 9 - 3 / 4 4 * -|-7"
    "8 9 * 9 - 1 1 1 - - - 1 / 2 / 9 - 2 / 9 - 8 8 8 - - - |-6"
    "6 6 * 9 - 3 / 4 4 * *|144"
    "2 2 2 2 * * * 2 -|14"
    "3 3 + 2 2 + *|24"
    # ERROR HANDLING
    "       |Error"
    "      4 4 +,|Error"
    " |Error"
    "|Error"
    "5|Error"
    "0|Error"
    "+|Error"
    "3 +|Error"
    "4 5 * +|Error"
    "3 3 + x|Error"
    "5 0 /|Error"
    "3 3 + +|Error"
    "3 x +|Error"
    "10|Error"
    "-2|Error"
    "2 3 + + 4|Error"
    "3 3 + -|Error"
    "3 +|Error"
    "3 3 3 + |Error"
    "3 0 /|Error"
    "3 3 3|Error"
    "a 3 3 |Error"
    "3 + 3 |Error"
    # DECIMAL RESULTS
    # "3 3 3 3 * + /|0.25"
    # "3 5 /|0.6"
    # "8 3 + 2 * 4 /|5.5"
    # "3 3 3 + /|0.5"
    # "6 6 * 9 - 8 / 4 4 * *|54" #requires precision
)

make

run_test()
{
    local input=$1
    local expected=$2

    ((TOTAL_TESTS++))
    output=$($EXECUTABLE "$input" 2>&1)

    if [[ "$output" == "$expected" ]]; then
        echo -e "${GREEN}PASS${RESET}"
        ((PASSED_TESTS++))
    else
        echo -e "${RED}FAIL${RESET}"
    fi
    echo -e "Input: '$input'\nExpected: '$expected'\nOutput: '$output'\n"
}

# Run all test cases
for test in "${TESTS[@]}"; do
    IFS="|" read -r input expected <<< "$test"
    run_test "$input" "$expected"
done

percentage=$((PASSED_TESTS * 100 / TOTAL_TESTS))
if ((percentage == 100)); then
    COLOR=${GREEN}
else
    COLOR=${RED}
fi
echo -e "Tests passed: ${COLOR}${PASSED_TESTS}/${TOTAL_TESTS} (${percentage}%)${RESET}"

make fclean