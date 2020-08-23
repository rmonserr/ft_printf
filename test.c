#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	x = 430;

	printf ("%.s\n", "Hello");
	ft_printf ("%.s\n", "Hello");
}

//   00034
//00034

//("%8.3i", 8375)

//expected output : "    8375"
//your output     : "     8375"
