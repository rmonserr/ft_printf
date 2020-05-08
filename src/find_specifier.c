#include "ft_printf.h"

void	specifier(t_printf *data)
{
	int		counter = 0;

	while(data->format[counter])
	{
		if(data->format[counter] == '%')
		{
			counter++;
			if(data->format[counter] == 'i' || data->format[counter] == 'd')
			{
				data->integer  = va_arg(data->args, int);
				printf("%d\n", data->integer);
			}
			if(data->format[counter] == 'c')
			{
				data->character = va_arg(data->args, int);
				printf("%c\n", data->character);
			}
			if(data->format[counter] == 's')
			{
				data->string = va_arg(data->args, char*);
				printf("%s\n", data->string);
			}
		}
		counter++;
	}
}
