#include "ft_printf.h"

t_printf	*init(t_printf *data, char *format)
{
	data->format = format;
	data->character = '0';
	data->integer = 0;
	data->string = NULL;
	data->len = 0;
	return(data);
}
