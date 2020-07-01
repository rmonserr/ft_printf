/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:39:38 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/01 13:39:39 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		read_flag(t_params *data, char *format)
{
	while ((ft_strchr(data->specifier_mask, format[data->counter]) == NULL))
	{
		if (format[data->counter] == '#')
			data->hash = 1;
		else if (format[data->counter] == '0')
			data->zero = 1;
		else if (format[data->counter] == '+')
			data->plus_sign = 1;
		else if (format[data->counter] == '-')
			data->minus_sign = 1;
		else if (format[data->counter] == ' ')
			data->space = 1;
		data->counter++;
		
	}
}

void		parcer(t_params *data, char *format)
{
	if (format[0] == '%' && format[1] == '\0')
		return ;
	while (format[data->counter])
	{
		if (format[data->counter] == '%')
		{
			data->counter++;
			read_flag(data, format);
		}
		data->counter++;
	}
}