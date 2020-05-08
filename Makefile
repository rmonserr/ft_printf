
NAME = ft_printf

SRCS = src/exit_func.c src/ft_printf.c src/initialization.c src/find_specifier.c

INCLUDES = -I includes -I.
LIB = -L libft libft/libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -g $(SRCS) $(LIB) $(INCLUDES) libft/libft/ft_putstr.c -o $(NAME) -std=c11

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
