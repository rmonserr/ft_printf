/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:51:29 by rmonserr          #+#    #+#             */
/*   Updated: 2020/06/30 13:51:35 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_params	*init(t_params *data, char *format)
{
	data->format = format;
	data->precision = 0;
	data->width = 0;
	data->minus_sign = 0;
	data->plus_sign = 0;
	data->space = 0;
	data->zero = 0;
	data->hash = 0;
	data->size = 0;
	data->counter = 0;
	data->specifier_mask = "sSeEpdDioOuUxXfgGcbC%";
	return(data);
}
