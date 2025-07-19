NAME    	=   libasm.a
BUILD   	=   build
INCLUDES	=   hdr
SRC_DIR 	=   src
TEST_DIR	=   test

SRC     	=   $(SRC_DIR)/ft_read.s \
        	    $(SRC_DIR)/ft_strcmp.s \
        	    $(SRC_DIR)/ft_strcpy.s \
        	    $(SRC_DIR)/ft_write.s \
        	    $(SRC_DIR)/ft_strlen.s \
        	    $(SRC_DIR)/ft_strdup.s

OBJ     	=   $(patsubst $(SRC_DIR)/%.s, $(BUILD)/%.o, $(SRC))

TEST_BIN	=   $(BUILD)/test_bin

GREEN   	=   \033[38;5;46m
WHITE   	=   \033[38;5;15m
RED     	=   \033[38;5;160m
BLUE    	=   \033[0;34m

FLAGS   	=   -Wall -Wextra -Werror

run_all:
	@bash ./run_all.sh

all: $(BUILD)/$(NAME)

$(BUILD)/$(NAME): $(OBJ) | $(BUILD)
	@echo "$(GREEN)Creating libasm.a in $(BUILD)/$(WHITE)"
	@ar rc $@ $(OBJ)
	@ranlib $@

$(BUILD)/%.o: $(SRC_DIR)/%.s | $(BUILD)
	@echo "$(BLUE)Compiling: $(WHITE)$<"
	@nasm -f elf64 -o $@ $<

$(BUILD):
	@mkdir -p $(BUILD)

test: $(BUILD)/$(NAME)
	@echo "$(BLUE)Compiling test binary$(WHITE)"
	@gcc $(FLAGS) -I$(INCLUDES) -L$(BUILD) \
	    $(TEST_DIR)/main.c \
	    $(TEST_DIR)/helper.c \
	    $(TEST_DIR)/tester.c \
	    $(TEST_DIR)/tester_functions.c \
	    $(TEST_DIR)/wrapper.c \
	    $(TEST_DIR)/auto_test.c \
	    -o $(TEST_BIN) -lasm -lc
	@echo "$(GREEN)Compiled main.c with libasm.a$(WHITE)"

run_test: test
	@echo "$(GREEN)Running test executable$(WHITE)"
	@$(TEST_BIN) $(ARGS)

clean:
	@echo "$(RED)Cleaning object files$(WHITE)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning all build artifacts$(WHITE)"
	@rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re test run_test
