#!/bin/bash

GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RESET="\033[0m"

echo -e "${YELLOW}🔧 Compiling project...${RESET}"
make re

echo -e "\n${GREEN}🔹 Test 1: Simple arguments${RESET}"
./megaphone "shhhhh... I think the students are asleep..."

echo -e "\n${GREEN}🔹 Test 2: Phrase with punctuation${RESET}"
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."

echo -e "\n${GREEN}🔹 Test 3: No arguments${RESET}"
./megaphone

echo -e "\n${GREEN}🔹 Test 7: Valgrind (checking for leaks)${RESET}"
valgrind --leak-check=full --error-exitcode=1 ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."

if [ $? -eq 0 ]; then
    echo -e "${GREEN}✔️  Valgrind: No leaks detected.${RESET}"
else
    echo -e "${YELLOW}⚠️  Valgrind detected memory issues!${RESET}"
fi

echo -e "\n${YELLOW}✔️  Tests completed.${RESET}"
