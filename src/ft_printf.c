#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	char *str;
	int a = 0;
	int b = 0;
	t_printf *data;

	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
		return(-1);
	if(format)
	{
		data = init(data, format);
		va_start(data->args, format);
		str = va_arg(data->args, char*);
		a = va_arg(data->args , int);
		//b = va_arg(data->args, int);
		printf("%d\n", a);
		printf("%s\n", str);
		va_end(data->args);
	}
	return(0);
}

int		main()
{
	ft_printf("%i", "Hello", 10);
	return (0);
}
