#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{

	char *str;

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
	ft_printf ("ft - %*.*s\n", -10, -4, "Helo");
	printf ("pt - %*.*s\n", -10, -4, "Helo");
	//octal_calculation(8375);
	//ft_putchar('\n');
	//printf ("%.3i\n",-23646);
	//char *str = "    00023\n";
	//ft_putstr(str);
}

