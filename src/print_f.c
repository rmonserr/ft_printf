/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:30:02 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/19 15:30:10 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_make_output(long double nbr, int arg, t_params *data, int count,
						int flag)
{
	char	*output;
	char	*str;
	int		i;
	int		a;

	str = (flag == 1 ? ft_strjoin("-", ft_itoa(arg)) : ft_itoa(arg));
	output = ft_strnew(ft_strlen(str) + count + 2);
	if (output)
	{
		output = copy(output, str);
		i = ft_strlen(str);
		output[i] = (data->hash == 1 ? ',' : '.');
		while (++i < (int)ft_strlen(str) + count + 1)
		{
			nbr *= 10;
			output[i] = (char)((char)nbr + 48);
			a = (int)nbr;
			nbr -= a;
		}
		output[ft_strlen(str) + count + 1] = '\0';
		if ((char)(nbr * 10) + 48 > '5')
			output = rounding(output);
	}
	return (output);
}

char	*use_zero(t_params *data, char *output)
{
	int	count;

	if (data->width > (int)ft_strlen(output) && !data->minus_sign && data->zero)
	{
		if (data->space)
			count = data->width - (int)ft_strlen(output) - 1;
		else
			count = data->width - (int)ft_strlen(output);
		while (count > 0)
		{
			output = ft_strjoin("0", output);
			count--;
		}
	}
	return (output);
}

char	*use_flag(t_params *data, char *output)
{
	int	count;

	if (data->plus_sign)
		if (output[0] != '-')
			output = ft_strjoin("+", output);
	output = use_zero(data, output);
	if (data->space && data->plus_sign == 0)
		output = ft_strjoin(" ", output);
	if (data->width > (int)ft_strlen(output))
	{
		count = data->width - (int)ft_strlen(output);
		while (count > 0)
		{
			if (data->minus_sign && data->zero == 0)
				output = ft_strjoin(output, " ");
			else
				output = ft_strjoin(" ", output);
			count--;
		}
	}
	return (output);
}

void	print_f(t_params *data)
{
	long double	arg;
	char		*output;
	int			a;
	int			flag;

	if (data->size == 5)
		arg = va_arg(data->args, long double);
	else
		arg = va_arg(data->args, double);
	a = (int)arg;
	flag = (arg < 0 && a == 0 ? 1 : 0);
	arg = (arg < 0 ? (-1) : 1) * (arg - a);
	if (data->precision < 0)
		output = ft_make_output(arg, a, data, 6, flag);
	else if (data->precision == 0)
	{
		output = (flag == 1 ? ft_strjoin("-", ft_itoa(a)) : ft_itoa(a));
		if ((char)((arg) * 10) + 48 > '5')
			output = rounding(output);
	}
	else
		output = ft_make_output(arg, a, data, data->precision, flag);
	output = use_flag(data, output);
	ft_putstr(output);
	data->total += ft_strlen(output);
}
