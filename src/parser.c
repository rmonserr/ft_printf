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

void		read_precision(t_params *data, char *format)
{
	int		tmp_counter;
	int		tmp_counter1;
	char	*tmp;

	if ((format[data->counter] == '.') && (format[data->counter + 1] >= '0'
		|| format[data->counter + 1] <= '9' ))
	{
		data->counter++;
		tmp_counter = 0;
		tmp_counter1 = data->counter;
		while(format[data->counter++] >= '0' && format[data->counter++] <= '9')
			tmp_counter++;
		tmp = ft_strnew(tmp_counter);
		tmp_counter1 += tmp_counter;
		data->counter -= tmp_counter;
		tmp_counter = 0;
		while (data->counter != tmp_counter1)
			tmp[tmp_counter++] = format[data->counter++];
			tmp_counter++;
			data->counter++;
		data->counter++;
		data->precision = ft_atoi(tmp);
		free(tmp);
	}
}

void		read_width(t_params *data, char *format)
{
	char	*tmp;
	int		tmp_counter;
	int		tmp_counter1;

	tmp_counter = 0;
	tmp_counter1 = data->counter;
	while(format[data->counter] >= '0' && format[data->counter] <= '9')
	{
		data->counter++;
		tmp_counter++;
	}
	tmp = ft_strnew(tmp_counter);
	tmp_counter1 += tmp_counter;
	data->counter -= tmp_counter;
	tmp_counter = 0;
	while (data->counter != tmp_counter1)
		tmp[tmp_counter++] = format[data->counter++];
	data->width = ft_atoi(tmp);
	free(tmp);
}

void		read_flag(t_params *data, char *format)
{
	while ((ft_strchr(data->flag_mask, format[data->counter]) != NULL))
	{
		if (format[data->counter] == '#')
			data->hash = 1;
		if (format[data->counter] == '0')
			data->zero = 1;
		if (format[data->counter] == '+')
			data->plus_sign = 1;
		if (format[data->counter] == '-')
			data->minus_sign = 1;
		if (format[data->counter] == ' ')
			data->space = 1;
		data->counter++;
	}
}

void		parcer(t_params *data, char *format)
{
	read_flag(data, format);
	read_width(data, format);
	read_precision(data, format);
	data->type = format[data->counter];
}

void		read_specifier(t_params *data, char *format)
{
	while (format[data->counter])
	{
		if (format[data->counter] == '%')
		{
			data->counter++;
			parcer(data, format);
		}
		else
			ft_putchar(format[data->counter]);
		data->counter++;
	}
}