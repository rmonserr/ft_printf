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

void		print_with_width_and_minus(t_params *data, int counter)
{
	if (data->negative == 1)
	{
		ft_putchar('-');
		data->negative = 0;
	}
	if (data->printed == 1 && !data->precision)
	{
		ft_putstr(data->output_str);
		data->printed = 0;
	}
	if (data->printed == 1 && data->precision)
		print_with_precision(data);
	while (counter-- > 0)
	{
		if (data->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

void		print_with_width(t_params *data, int counter)
{
	if (data->negative == 1 && data->zero)
	{
		ft_putchar('-');
		data->negative = 0;
	}
	while (counter-- > 0)
	{
		if (data->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (data->negative == 1)
	{
		ft_putchar('-');
		data->negative = 0;
	}
	if (data->printed == 1 && !data->precision)
	{
		ft_putstr(data->output_str);
		data->printed = 0;
	}
}

void		function_parsing(t_params *data)
{
	int		counter;

	if (data->precision && data->width < data->precision)
		print_with_precision(data);
	else
	{
		if (data->precision &&
			data->precision > (int)ft_strlen(data->output_str))
			counter = data->width - data->precision;
		else
			counter = data->width - (int)ft_strlen(data->output_str);
		if (data->negative)
			counter -= 1;
		if (data->minus_sign == 1)
			print_with_width_and_minus(data, counter);
		else
			print_with_width(data, counter);
		print_with_precision(data);
	}
}

int			print_zero(t_params *data)
{
	if (data->precision == 0 && !data->width)
	{
		data->printed = 0;
		return (1);
	}
	if (!data->precision && data->width)
	{
		data->printed = 0;
		while (data->width--)
			ft_putchar(' ');
		return (1);
	}
	if (!data->precision)
	{
		data->printed = 0;
		return (1);
	}
	return (0);
}

void		print_integer(t_params *data)
{
	int		arg;

	arg = va_arg(data->args, int);
	// здесь будет проверка на size - меняем size и переходим далее
	// прикрутить флаги ' '
	if (data->zero == 1 && data->precision > 0)
		data->zero = 0;
	if (arg < 0)
	{
		data->output_str = ft_itoa(arg * (-1));
		data->negative = 1;
	}
	else
	{
		data->output_str = ft_itoa(arg);
		data->negative = 0;
	}
	//printf ("%d\n", arg);
	data->printed = 1;
	if ((int)ft_strlen(data->output_str) == 1 && data->output_str[0] == '0')
		data->trigger = print_zero(data);
	if (data->trigger == 1)
		return ;
	else
		function_parsing(data);
}
