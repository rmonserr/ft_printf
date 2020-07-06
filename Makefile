# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 15:12:11 by rmonserr          #+#    #+#              #
#    Updated: 2020/07/01 15:23:02 by rmonserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRCS = src/ft_printf.c src/initialization.c src/parser.c \
src/parser_pt_2.c src/print.c src/print_operations.c src/print_with_flags.c

INCLUDES = -I includes -I.
LIB = -L libft -lft

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) -g $(SRCS) $(LIB) $(INCLUDES) -o $(NAME)
	@echo "Compilation of ft_printf:	\033[1;32mOK\033[m"

fclean:
	@rm -f $(NAME)
	@echo "ft_printf:	\033[1;32mRemoving ft_printf\033[m"

re: fclean all

.PHONY: all clean fclean re
