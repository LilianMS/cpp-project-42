#!/bin/bash

GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
RESET="\033[0m"

EXEC=./zombie
EXPECTED1="HeapZombie: BraiiiiiiinnnzzzZ..."
EXPECTED2="StackZombie: BraiiiiiiinnnzzzZ..."

echo -e "${YELLOW}🔧 Compiling with Makefile...${RESET}"
make re

if [ ! -f $EXEC ]; then
    echo -e "${RED}❌ Error: executable not found.${RESET}"
    exit 1
fi

echo -e "${YELLOW}▶️ Running ${EXEC}...${RESET}"
OUTPUT=$($EXEC)

echo -e "\n${YELLOW}📤 Program output:${RESET}"
echo "$OUTPUT"

# Checks
echo -e "\n${YELLOW}🔎 Checking expected output...${RESET}"

if echo "$OUTPUT" | grep -q "$EXPECTED1"; then
    echo -e "${GREEN}✅ HeapZombie OK${RESET}"
else
    echo -e "${RED}❌ HeapZombie missing or incorrect${RESET}"
fi

if echo "$OUTPUT" | grep -q "$EXPECTED2"; then
    echo -e "${GREEN}✅ StackZombie OK${RESET}"
else
    echo -e "${RED}❌ StackZombie missing or incorrect${RESET}"
fi

# Valgrind (optional)
echo -e "\n${YELLOW}🔬 Checking memory with Valgrind...${RESET}"
valgrind --leak-check=full --error-exitcode=1 $EXEC > /dev/null 2>&1

if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ No memory leaks detected.${RESET}"
else
    echo -e "${RED}❌ Memory leak detected!${RESET}"
fi
