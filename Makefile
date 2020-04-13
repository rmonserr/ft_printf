
NAME = ft_printf

SRCS = src/exit_func.c src/ft_printf.c

INCLUDES = -I includes -I.
LIB = -L libft libft/libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) $(LIB) $(INCLUDES) libft/libft/ft_putstr.c -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
