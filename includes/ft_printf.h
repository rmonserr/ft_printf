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
	int			total;
	char		type;
	char		*specifier_mask;
	char		*flag_mask;
	char		*output_str;
}				t_params;

t_params	*init(t_params *data, char *format);
void		clean_struct(t_params *data);
void		parcer(t_params *data, char *format);
void		read_specifier(t_params *data, char *format);
void		read_flag(t_params *data, char *format);
void		read_width(t_params *data, char *format);
void		read_precision(t_params *data, char *format);
void		read_size(t_params *data, char *format);
void		sort_flags(t_params *data);
void		type_parsing(t_params *data, char *format);
void		print_integer(t_params *data);


# endif
