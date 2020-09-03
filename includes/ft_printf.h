#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

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
char		*move_minus(char *str);
int			print_zero(t_params *data);
char		*put_minus(int len, char *str);
char		*print_int_3(t_params *data, int len, char *str);
char		*print_int_2(t_params *data, int len, char *str);
void		print_int(t_params *data);

//char
void		print_char(t_params *data);
void		print_char_with_width(t_params *data);
void		print_string(t_params *data);

//str
void		print_string(t_params *data);
char		*print_string_2(t_params *data, long int len, char *str);
char		*print_string_3(t_params *data, int len, char *str);
char		*check_null(t_params *data, char *str);

//octal
void		print_octal(t_params *data);
char		*octal_calculation(long long int number, t_params *data);
char		*print_octal_2(t_params *data, char *str, int len);
char		*print_octal_3(t_params *data, char *str, int len);

char		*ft_itoa(long long int n);
void		ft_putchar(char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strnew(size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putstr(char const *s);
int			ft_isspace(int c);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_memdel(void **ap);
char		*ft_revstring(char *str);


char		*move_minus(char *str);

# endif
