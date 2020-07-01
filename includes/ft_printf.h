#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"
#include <stdlib.h>

typedef struct	s_params
{
	va_list		args;
	char		*format;
	long int	precision;
	long int	width;
	int			minus_sign;
	int			plus_sign;
	int			space;
	int			zero;
	int			hash;
	size_t		size;
	int			counter;
}				t_params;

t_params	*init(t_params *data, char *format);
void		parcer(t_params *data, char *format);
void		read_flag(t_params *data, char *format)
void		specifier(t_printf *data);
void		exit_func(void);
void		int_output(int num);
void		output(char *str);
void		character_output(char c);

# endif
