#!/bin/bash

# Color definitions
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

EXEC=./replace
FILENAME=testfile.txt

cleanup() {
    rm -f "$FILENAME" "$FILENAME.replace"
}

run_valgrind() {
    echo -e "${YELLOW}🔍 Valgrind output:${NC}"
    valgrind --leak-check=full --error-exitcode=1 "$@"
}

echo -e "${CYAN}🧪 Test 1: basic replacements${NC}"
cleanup
echo -e "hello world\nhello again\nsay hello!" > "$FILENAME"
run_valgrind $EXEC "$FILENAME" "hello" "hi"
echo -e "${YELLOW}📄 Result:${NC}"
cat "$FILENAME.replace"
echo -e "${GREEN}\n---${NC}"

echo -e "${CYAN}🧪 Test 2: no occurrence of s1${NC}"
cleanup
echo "this text does not match s1" > "$FILENAME"
run_valgrind $EXEC "$FILENAME" "xxx" "yyy"
echo -e "${YELLOW}📄 Result:${NC}"
cat "$FILENAME.replace"
echo -e "${GREEN}\n---${NC}"

echo -e "${CYAN}🧪 Test 3: empty file${NC}"
cleanup
touch "$FILENAME"
run_valgrind $EXEC "$FILENAME" "a" "b"
echo -e "${YELLOW}📄 Result:${NC}"
cat "$FILENAME.replace"
echo -e "${GREEN}\n---${NC}"

echo -e "${CYAN}🧪 Test 4: nonexistent file${NC}"
cleanup
run_valgrind $EXEC "nonexistent.txt" "a" "b"
echo -e "${GREEN}\n---${NC}"

echo -e "${CYAN}🧪 Test 5: empty s1${NC}"
cleanup
echo "some content" > "$FILENAME"
run_valgrind $EXEC "$FILENAME" "" "X"
echo -e "${GREEN}\n---${NC}"

echo -e "${CYAN}🧪 Test 6: empty s2${NC}"
cleanup
echo "replace me" > "$FILENAME"
run_valgrind $EXEC "$FILENAME" "replace" ""
echo -e "${GREEN}\n---${NC}"

echo -e "${CYAN}🧪 Test 7: missing arguments${NC}"
cleanup
run_valgrind $EXEC "$FILENAME" "only_two_args"
echo -e "${GREEN}\n---${NC}"

cleanup
