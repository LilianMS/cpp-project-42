#!/bin/bash

GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RESET="\033[0m"

EXEC="./phonebook"
BUILD_CMD="make re"

echo -e "${YELLOW}🔧 Building the project...${RESET}"
$BUILD_CMD

if [ ! -f $EXEC ]; then
    echo -e "${YELLOW}❌ Executable not found.${RESET}"
    exit 1
fi

echo -e "${GREEN}✅ Executable built successfully.${RESET}"

# Simulate input with commands via printf and redirect to the executable
echo -e "\n${GREEN}🔹 Test 1: Invalid command, ADD, SEARCH and EXIT with valid index${RESET}"
printf "TEST\nADD\nJohn\nSmith\nJSmith\n11999999999\nLoves lasagna\nSEARCH\n0\nEXIT\n" | valgrind $EXEC

echo -e "\n${GREEN}🔹 Test 2: SEARCH with invalid index${RESET}"
printf "ADD\nAnna\nLima\nAnnie\n21988888888\nAfraid of clowns\nSEARCH\n9\nEXIT\n" | valgrind $EXEC

echo -e "\n${GREEN}🔹 Test 3: Only EXIT command${RESET}"
printf "EXIT\n" | valgrind $EXEC

echo -e "\n${GREEN}🔹 Test 4: Automatically fill 8 contacts and replace${RESET}"
for i in {1..9}; do
    printf "ADD\nName$i\nSurname$i\nNick$i\n9999999999$i\nSecret$i\n" >> input.txt
done
echo "SEARCH" >> input.txt
echo "7" >> input.txt
echo "EXIT" >> input.txt
valgrind $EXEC < input.txt
rm input.txt

echo -e "\n${YELLOW}✔️ Tests completed.${RESET}"
