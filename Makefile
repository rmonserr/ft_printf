
NAME = ft_printf

SRCS = src/exit_func.c src/ft_printf.c src/initialization.c src/find_specifier.c \
src/output.c

INCLUDES = -I includes -I.
LIB = -L libft -lft

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -g $(SRCS) $(LIB) $(INCLUDES) -o $(NAME) -std=c11

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
