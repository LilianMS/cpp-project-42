#!/bin/bash

GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RESET="\033[0m"

EXEC="valgrind ./phonebook"
BUILD_CMD="make re"

echo -e "${YELLOW}🔧 Compilando o projeto...${RESET}"
$BUILD_CMD

if [ ! -f $EXEC ]; then
    echo -e "${YELLOW}❌ Executável não encontrado.${RESET}"
    exit 1
fi

echo -e "${GREEN}✅ Executável compilado com sucesso.${RESET}"

# Simular entrada com comandos via printf e redirecionar para o executável
echo -e "\n${GREEN}🔹 Teste 1: Comando inválido, ADD, SEARCH e EXIT com índice válido${RESET}"
printf "TESTE\nADD\nJoão\nSilva\nJSilva\n11999999999\nAdora lasanha\nSEARCH\n0\nEXIT\n" | $EXEC

echo -e "\n${GREEN}🔹 Teste 2: SEARCH com índice inválido${RESET}"
printf "ADD\nAna\nLima\nAninha\n21988888888\nTem medo de palhaço\nSEARCH\n9\nEXIT\n" | $EXEC

echo -e "\n${GREEN}🔹 Teste 3: Apenas comando EXIT${RESET}"
printf "EXIT\n" | $EXEC

echo -e "\n${GREEN}🔹 Teste 4: Preenchimento automático dos 8 contatos e substituição${RESET}"
for i in {1..9}; do
    printf "ADD\nNome$i\nSobrenome$i\nNick$i\nTelefone$i\nSegredo$i\n" >> input.txt
done
echo "SEARCH" >> input.txt
echo "7" >> input.txt
echo "EXIT" >> input.txt
$EXEC < input.txt
rm input.txt

echo -e "\n${YELLOW}✔️ Testes concluídos.${RESET}"
