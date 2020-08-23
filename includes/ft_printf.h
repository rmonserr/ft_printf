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
	int			negative;
	int			printed;
	int			trigger;
	char		type;
	char		*specifier_mask;
	char		*flag_mask;
	char		*output_str;
}				t_params;

int			ft_printf(char *format, ...);
t_params	*init(t_params *data, char *format);
void		clean_struct(t_params *data);
void		parcer(t_params *data, char *format);
void		read_specifier(t_params *data, char *format);
void		read_flag(t_params *data, char *format);
void		read_width(t_params *data, char *format);
void		read_precision(t_params *data, char *format);
void		read_size(t_params *data, char *format);
void		sort_flags(t_params *data);
void		type_parsing(t_params *data);

//int
void		print_integer(t_params *data);
void		print_with_width(t_params *data, int counter);
void		print_with_width_and_minus(t_params *data, int counter);
int			print_zero(t_params *data);
int			prec_check(t_params *data);
void		print_with_precision(t_params *data);
void		zero_fill(t_params *data);
void		function_parsing(t_params *data);

//char
void		print_char(t_params *data);
void		print_char_with_width(t_params *data);
void		print_string(t_params *data);

char		*ft_itoa(int n);
void		ft_putchar(char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strnew(size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putstr(char const *s);
int			ft_isspace(int c);

# endif
