#include "ft_printf.h"

void		int_output(int num)
{
	char *str;

	str = ft_itoa(num);
	output(str);
	free(str);
}

void		character_output(char c)
{
	putchar(c);
}


void		output(char *str)
{
	ft_putstr(str);
}
