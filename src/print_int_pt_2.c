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

int			prec_check(t_params *data)
{
	if (data->precision <= (int)ft_strlen(data->output_str))
	{
		if (data->printed == 1)
		{
			if (data->negative == 1)
				ft_putchar('-');
			ft_putstr(data->output_str);
			data->printed = 0;
		}
		return (1);
	}
	return (0);
}

void		print_with_precision(t_params *data)
{
	int		counter;

	if ((prec_check(data) == 1))
		return ;
	counter = data->precision - (int)ft_strlen(data->output_str);
	if (data->negative == 1)
	{
		data->negative = 0;
		ft_putchar('-');
	}
	while (counter-- > 0)
		ft_putchar('0');
	if (data->printed == 1)
	{
		ft_putstr(data->output_str);
		data->printed = 0;
	}
	data->precision = 0;
}

void		zero_fill(t_params *data)
{
	int		counter;

	if (data->precision)
		return ;
	counter = data->width - (int)ft_strlen(data->output_str) - data->negative;
	if (data->negative == 1)
	{
		ft_putchar('-');
		data->negative = 0;
	}
	while (counter-- > 0)
		ft_putchar('0');
	if (data->printed == 1)
	{
		ft_putstr(data->output_str);
		data->printed = 0;
	}
}
