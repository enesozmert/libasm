NAME    =   libasm.a

SRC     =   src/ft_read.asm \
            src/ft_strcmp.asm \
            src/ft_strcpy.asm \
            src/ft_write.asm \
            src/ft_strlen.asm \
            src/ft_strdup.asm

GREEN   =   \033[38;5;46m
WHITE   =   \033[38;5;15m
RED     =   \033[38;5;160m
BLUE    =   \033[0;34m

SRC_O   =   $(SRC:.asm=.o)

FLAGS   =   -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "$(GREEN)Creating libasm.a$(WHITE)"
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)

%.o: %.asm
	@echo "$(BLUE)Compiling: $(WHITE)$<"
	@nasm -f elf64 -o $@ $<

test: $(NAME)
	@gcc $(FLAGS) -L. test_cases/main.c -o test -lasm -lc
	@echo "$(GREEN)Compiled main.c with libasm.a$(WHITE)"

run_test: test
	@echo "$(GREEN)Running test executable$(WHITE)"
	@./test "help"

clean:
	@echo "$(RED)Cleaning all .o files$(WHITE)"
	@rm -f $(SRC_O)

fclean: clean
	@echo "$(RED)Cleaning all .a files and test executable$(WHITE)"
	@rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test run_test
