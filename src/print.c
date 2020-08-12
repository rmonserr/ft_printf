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

void		print_with_width(t_params *data)
{
	int		counter;

	counter = 0;
	while (counter < data->width - (int)ft_strlen(data->output_str))
	{
		ft_putchar(' ');
		counter++;
	}
}

void		print_integer(t_params *data)
{
	// здесь будет проверка на size - меняем size и переходим далее
	data->output_str = ft_itoa(va_arg(data->args, int));
	print_with_width(data);
	ft_putstr(data->output_str);
}
