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

void		output(char *str,int counter)
{
	int		tmp;

	tmp = 0;
	while (counter != tmp)
		ft_putchar(str[tmp++]);
}

void		print_string_with_prec(t_params *data, char *str)
{
	int		counter;

	if (data->precision > 0 && data->precision < (int)ft_strlen(str))
	{
		counter = data->precision;
		data->printed = 0;
		output(str, counter);
	}
	if (data->precision == 0)
		data->printed = 0;
}

void		print_string_with_width(t_params *data, char *str)
{
	int		counter;

	counter = data->width - (int)ft_strlen(str);
	if (counter < 0)
		return ;
	while (counter-- > 0)
		ft_putchar(' ');
}

void		print_string(t_params *data)
{
	char *str = va_arg(data->args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	data->printed = 1;
	if (data->precision >= 0)
		print_string_with_prec(data, str);
	if (data->printed && !data->width)
	{
		ft_putstr(str);
		data->printed = 0;
	}
	if (data->printed && data->width != 0 && data->minus_sign)
	{
		ft_putstr(str);
		data->printed = 0;
		print_string_with_width(data, str);
	}
	else if (data->printed && data->width && !data->minus_sign)
	{
		print_string_with_width(data, str);
		ft_putstr(str);
		//data->printed = 0;
	}
}

