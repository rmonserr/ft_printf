/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:51:10 by rmonserr          #+#    #+#             */
/*   Updated: 2020/06/30 13:51:17 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int		ft_printf(char *format, ...)
{
	t_params	*data;
	int			res;

	res = 0;
	if (format)
	{
		if (!(data = (t_params *)malloc(sizeof(t_params))))
			return (-1);
		data = init(data, format);
		va_start(data->args, format);
		if (format[0] == '%' && format[1] == '\0')
			return (0);
		read_specifier(data);
		va_end(data->args);
	}
	else
		exit (-1);
	res = data->total;
	free (data);
	return (res);
}
