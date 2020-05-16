#include "ft_printf.h"

void	specifier(t_printf *data)
{
	int		counter = 0;

	while (data->format[counter])
	{
		if (data->format[counter] == '%')
		{
			counter++;
			if (data->format[counter] == 'i')
			{
				data->integer  = va_arg(data->args, int);
				int_output(data->integer);
			}
			if (data->format[counter] == 'c')
			{
				data->character = va_arg(data->args, int);
				character_output(data->character);
			}
			if (data->format[counter] == 's')
			{
				data->string = va_arg(data->args, char*);
				output(data->string);
			}
			if (data->format[counter] == 'f')
			{
				data->flt = va_arg(data->args, double);
				printf("%f\n", data->flt);
			}
			if (data->format[counter] == 'd')
			{
				data->doub = va_arg(data->args, double);
				printf("%f\n", data->doub);
			}
		}
		counter++;
	}
}
