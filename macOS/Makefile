NAME = ft_printf

SRCS = exit_func.c find_specifier.c ft_printf.c
SRC_PATH = src

OBJ_PATH = obj
OBJS = $(SRC_1:.c=.o)

INCLUDES = -I includes -I.
LIB = -L libft libft/libft/libft.a

SRC = $(addprefix $(SRC_PATH)/, $(SRCS))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJS))

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(LIB) $^ -o $@
	@echo "Compilation of ft_printf:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "ft_printf: \033[1;32mRemoving Objs\033[m"

fclean:
	@rm -f $(NAME)
	@echo "ft_printf: \033[1;32mRemoving ft_printf\033[m"

re: fclean all

.PHONY: all clean fclean re
