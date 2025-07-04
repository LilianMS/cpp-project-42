#!/bin/bash

YELLOW="\033[1;33m"
GREEN="\033[1;32m"
RED="\033[1;31m"
RESET="\033[0m"

EXEC="./account_test"
REF_LOG="19920104_091532.log"
TMP_LOG="my_output.log"
CLEAN_TMP="my_clean.log"
CLEAN_REF="expected_clean.log"

echo -e "${YELLOW}🔧 Compiling the project...${RESET}"
make re

if [ ! -f $EXEC ]; then
    echo -e "${RED}❌ Error: binary not found.${RESET}"
    exit 1
fi

echo -e "${YELLOW}▶️ Running the program...${RESET}"
$EXEC > $TMP_LOG

echo -e "${YELLOW}🔎 Comparing output with reference log (with timestamps)...${RESET}"
if diff -u "$TMP_LOG" "$REF_LOG" > /dev/null; then
    echo -e "${GREEN}✅ Success: output is identical to the reference log.${RESET}"
else
    echo -e "${RED}❌ Failure: difference found with timestamps.${RESET}"
    echo -e "${YELLOW}Suggestion: comparing while ignoring timestamps...${RESET}"

    # Comparison ignoring timestamp
    cut -d']' -f2- "$TMP_LOG" > "$CLEAN_TMP"
    cut -d']' -f2- "$REF_LOG" > "$CLEAN_REF"

    if diff -u "$CLEAN_TMP" "$CLEAN_REF" > /dev/null; then
        echo -e "${GREEN}✅ Logic is correct! Only the timestamp is different.${RESET}"
    else
        echo -e "${RED}❌ Incorrect logic: differences found even without timestamps.${RESET}"
        echo -e "${YELLOW}Use 'diff $CLEAN_TMP $CLEAN_REF' to inspect manually.${RESET}"
    fi
fi

# Temporary cleanup
rm -f "$CLEAN_TMP" "$CLEAN_REF"


# make
# ./account_test > my_output.log

# diff my_output.log 19920104_091532.log

# cut -d']' -f2 my_output.log > my_clean.log
# cut -d']' -f2 19920104_091532.log > expected_clean.log
# diff my_clean.log expected_clean.log

