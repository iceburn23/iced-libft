SRC_PART = ./ft_printf.c ./ft_printf_checkers.c
SRC_BONUS =
NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
CC = gcc -c
HDRS = libftprintf.h
OBJ_PART = $(SRC_PART:.c=.o)
OBJ_BONUS = $(OBJ_PART) $(SRC_BONUS:.c=.o)

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME): $(OBJ_PART) $(HDRS)
	@$(CC) $(SRC_PART) $(FLAGS)
	@ar r $(NAME) $(OBJ_PART)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft.\033[0m"

bonus: $(OBJ_BONUS) $(HDRS)
	cp ../libft/libft.a ./libft.a
	@$(CC) $(SRC_PART) $(SRC_BONUS) $(FLAGS)
	@ar r $(NAME) $(OBJ_BONUS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft with Bonus.\033[0m"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ_BONUS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
