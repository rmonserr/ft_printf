#include "ft_printf.h"
#include <unistd.h>

void	ft_printf(const char *format, ...)
{
	va_list		list;
	int			ind;

	va_start(list, format);
	ind = 0;
	if (format[ind] != '%')
		exit_func();
	else
		ft_putstr("Feels good\n");
	va_end(list);
}

int		main()
{
	ft_printf("%");
}
