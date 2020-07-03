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

void		read_size(t_params *data, char *format)
{
	size_t 		h_size;
	size_t 		l_size;

	while(format[data->counter++] == 'h' || format[data->counter++] == 'l' ||
		format[data->counter++] == 'L')
	{
		if (format[data->counter] == 'h')
			h_size++;
		if (format[data->counter] == 'h')
			l_size++;
		if (format[data->counter] == 'L')
			data->size = 5;
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