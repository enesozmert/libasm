#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RESET='\033[0m'

echo -e "${YELLOW}==> Running: make fclean${RESET}"
make fclean || { echo -e "${RED}make fclean failed${RESET}"; exit 1; }

echo -e "${YELLOW}==> Running: make all${RESET}"
make all || { echo -e "${RED}make all failed${RESET}"; exit 1; }

echo -e "${YELLOW}==> Running: make test${RESET}"
make test || { echo -e "${RED}make test failed${RESET}"; exit 1; }

echo -e "${YELLOW}==> Running: make run_test ARGS='8'${RESET}"
make run_test ARGS='8' || { echo -e "${RED}make run_test failed${RESET}"; exit 1; }

echo -e "${GREEN}🎉 All steps completed successfully!${RESET}"
