
NAME = ft_printf

SRCS = src/exit_func.c src/ft_printf.c src/initialization.c src/find_specifier.c \
src/output.c

INCLUDES = -I includes -I.
LIB = -L libft -lft

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) -g $(SRCS) $(LIB) $(INCLUDES) -o $(NAME) -std=c11
	@echo "Compilation of ft_printf:	\033[1;32mOK\033[m"

fclean:
	@rm -f $(NAME)
	@echo "ft_printf:	\033[1;32mRemoving ft_printf\033[m"

re: fclean all

.PHONY: all clean fclean re
