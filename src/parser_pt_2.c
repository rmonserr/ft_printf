/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_pt_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:39:43 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/02 18:39:44 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		sort_flags(t_params *data)
{
	if (data->minus_sign == 1 && data->zero == 1)
		data->zero = 0;
	if (data->plus_sign == 1 && data->space == 1)
		data->space = 0;
}

void		read_size(t_params *data, char *format)
{
	size_t		h_size;
	size_t		l_size;

	h_size = 0;
	l_size = 0;
	while (format[data->counter] == 'h' || format[data->counter] == 'l' ||
		format[data->counter] == 'L')
	{
		if (format[data->counter] == 'h')
			h_size++;
		if (format[data->counter] == 'l')
			l_size++;
		if (format[data->counter] == 'L')
			data->size = 5;
		data->counter++;
	}
	if (h_size == 2)
		data->size = 4;
	if (h_size == 1)
		data->size = 3;
	if (l_size == 2)
		data->size = 2;
	if (h_size == 1)
		data->size = 1;
}

void		type_parsing(t_params *data)
{
	if (data->type == 'd' || data->type == 'i')
		print_integer(data);
	if (data->type == 'c' || data->type == 'C')
		print_char(data);
	if (data->type == 's' || data->type == 'S')
		print_string(data);
	if (data->type == '%')
		ft_putchar('%'); // сделать вывод с учетом ширины, точности и т.д.
}
