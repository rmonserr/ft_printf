#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_printf
{
	va_list		args;
	char		*format;
	char		*string;
	char		character;
	char		*buffer;
	int			integer;
	double		doub;
	float		flt;
	size_t		len;
}				t_printf;

t_printf	*init(t_printf *data, char *format);
void		specifier(t_printf *data);
void		exit_func(void);
void		int_output(int num);
void		output(char *str);
void		character_output(char c);

# endif
