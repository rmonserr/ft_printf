#include "ft_printf.h"

t_printf	*init(t_printf *data, char *format)
{
	data->format = format;
	data->len = 0;
	return(data);
}
