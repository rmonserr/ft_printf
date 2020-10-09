#include "../includes/ft_printf.h"

char	*ft_make_output(long double nbr, int arg, t_params *data)
{
	char	*output;
    char    *str;
	int		i;
	int		a;

	a = (int)nbr;
	nbr -= a;
	i = 0;
	str = ft_strnew(1);
    str = ft_itoa(arg);
	output = ft_strnew(ft_strlen(str) + 56);
	if (output)
	{
        while (i < (int)ft_strlen(str))
		{
            output[i] = str[i];
			i++;
		}
        output[i] = (data->hash == 1 ? ',' : '.');
		if (nbr < 0)
			nbr *= -1;
		while (++i < (int)ft_strlen(str) + 55)
		{
			nbr *= 10;
			a = (int)nbr;
			output[i] = (char)((char)nbr + 48);
			a = (int)nbr;
			nbr -= a;
		}
		output[ft_strlen(str) + 55] = '\0';
	}
	return (output);
}

//char    *ft_prec(t_params *data, char *output)
//{
//
    //return (output);
//}

void    print_f(t_params *data)
{
    long double arg;
    char        *output;
	int 		a;
    //int         len;
	float	t;

	if (data->size == 5 || data->size == 1)
		arg = va_arg(data->args, long double);
	else
	{
		arg = va_arg(data->args, double);
		t = (float)arg;
	}
	printf("t = %f\n", t);
	a = (int)arg;
    output = ft_make_output(arg + (arg < 0 ? 1 : (-1)) * a, a, data);
    if (arg < 0)
		data->negative = 1;
    //len = (int)ft_strlen(str) + 1 + (int)ft_strlen(output);
	ft_putstr(output);
}
