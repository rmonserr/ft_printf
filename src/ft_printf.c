#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	t_printf *data;

	if (!(data = (t_printf *)malloc(sizeof(t_printf))))
		return(-1);
	if(format)
	{
		data = init(data, format);
		va_start(data->args, format);
		specifier(data);
		va_end(data->args);
	}
	return(0);
}

int		main()
{
	printf( "%0*x", 8, 15 );
	//ft_printf("%s", "-");
	return (0);
}
