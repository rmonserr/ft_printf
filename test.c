#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	x = 430;

	//printf ("printf - .1 %.1o\n", 439);
	//printf ("printf - .2 %.2o\n", 439);
	//printf ("printf - .3 %.3o\n", 439);
	//printf ("printf - 13 %13o\n", 439);
	//printf ("printf - 13.3 %13.3o\n", 439);
	//printf ("printf - -3 %-3o\n", 439);
	//printf ("printf - -3.3 %-3.3o\n", 439);
	//printf ("printf - 3.3 %3.3o\n", 439);
	//printf ("printf - -10.2 %-10.2o\n", 439);
	//printf ("printf - -10. %-10.o\n", 439);
	//printf ("printf - . %.o\n", 439);
	//printf ("printf - 10.5 %10.5o\n", 439);
	//printf ("printf - 10.5 %-10.5o\n", 439);
	//printf ("printf - 10.5 %-10.5o\n", -439);
	//printf ("printf - %o\n", -4);
	//printf ("printf - %o\n", 1);
	//ft_printf ("ft_printf %10.6o\n", 123);
	//printf ("printf %10.6o\n", 123);
	ft_printf ("%07i", -54);
	//octal_calculation(8375);
	//ft_putchar('\n');
	//printf ("%.3i\n",-23646);
	//char *str = "    000-23";
	//str = print_minus(str);
	//ft_putstr(str);
}

