/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:12:55 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/02 15:12:56 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*octal_calculation(long long int number, t_params *data)
{
	char 	*res;
	int		tmp;
	char	*temp;

	tmp = 0;
	res = ft_strnew(0);
	if (number == 0  && data->precision != 0)
	{
		res = ft_itoa(number);
		return (res);
	}
	while (number / 8)
	{
		tmp = number / 8;
		//printf("%lld\n", number % 8);
		temp = ft_itoa(number % 8);
		res = ft_strjoin(res, temp);
		number = tmp;
	}
	if (number >= 0 && number % 8 != 0)
	{
		temp = ft_itoa(number % 8);
		res = ft_strjoin(res, temp);
	}
	if (data->hash == 1)
		res = ft_strjoin(res, "0");
	res = ft_revstring(res);
	//ft_putstr(res);
	return (res);
}

char		*print_octal_3(t_params *data, char *str, int len)
{
	char 	*new;
	int		count;
	char	c;

	count = 0;
	if (data->zero == 1 && data->precision < 0)
		c = '0';
	else
		c = ' ';
	if (data->width && data->width > len)
	{
		new = ft_strnew(data->width - len);
		while (count < data->width - len)
			new[count++] = c;
		if (data->minus_sign)
			new = ft_strjoin(str, new);
		else
			new = ft_strjoin(new, str);
		ft_strdel(&str);
		return (new);
	}
	return (str);
}

char		*print_octal_2(t_params *data, char *str, int len)
{
	char	*new;
	int		count;

	count = 0;
	if (data->precision > 0 && data->precision > len)
	{
		new = ft_strnew(data->precision - len);
		while (count < data->precision - len)
			new[count++] = '0';
		new = ft_strjoin(new, str);
		ft_strdel(&str);
		return (new);
	}
	return(str);
}

void		print_octal(t_params *data)
{
	char	*output;
	int		len;

	//printf("%ld\n", data->precision);
	//printf("%ld\n", data->width);
	//printf("%d\n", data->zero);

	output = octal_calculation(va_arg(data->args, unsigned long long int), data);
	//ft_putstr(output);
	//ft_putchar('\n');
	len = (long int)ft_strlen(output);
	output = print_octal_2(data, output, len);
	//ft_putstr(output);
	//ft_putchar('\n');
	len = (long int)ft_strlen(output);
	//printf("len %d\n", len);
	output = print_octal_3(data, output, len);
	ft_putstr(output);
}
