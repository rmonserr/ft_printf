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
	
}

void		parcer(t_params *data, char *format)
{
	if (format[0] == '%' && format[1] == '\0')
		return (0);
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