#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft/libft.h"
#include <stdio.h>


typedef struct	s_printf
{
	va_list		args;
	char		*format;
	size_t		len;
}				t_printf;

t_printf	*init(t_printf *data, char *format);
void		exit_func(void);

# endif
