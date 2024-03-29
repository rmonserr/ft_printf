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
		//printf("next = %c\n", (char)((nbr * 10 - (int)(nbr * 10)) * 10) + 48);
		if ((char)(nbr * 10) + 48 > '4')// || ((char)(nbr * 10) + 48 == '4'
			//&& ((char)((nbr * 10 - (int)(nbr * 10)) * 10) + 48 > '4')))
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

char	*use_flag(t_params *data, char *output, int flag)
{
	int	count;

	if (data->plus_sign && ft_strstr(output, "nan") == NULL)
		if (output[0] != '-')
			output = ft_strjoin("+", output);
	if (flag == 1)
		output = use_zero(data, output);
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

void	print_f(t_params *data, long double	arg)
{
	char		*output;
	int			a;
	int			flag;

	a = (int)arg;
	flag = (arg < 0 && a == 0 ? 1 : 0);
	arg = (arg < 0 ? (-1) : 1) * (arg - a);
	if (data->precision < 0)
		output = ft_make_output(arg, a, data, 6, flag);
	else if (data->precision == 0)
	{
		output = (flag == 1 ? ft_strjoin("-", ft_itoa(a)) : ft_itoa(a));
		if ((char)((arg) * 10) + 48 > '4')
			output = rounding(output);
	}
	else
		output = ft_make_output(arg, a, data, data->precision, flag);
	output = use_flag(data, output, 1);
	ft_putstr(output);
	data->total += ft_strlen(output);
}

char		*floatld_inf_or_nan(int mant, int sign)
{
	char	*ret;

	ret = NULL;
	if (mant == 0)
	{
		if (sign == 1)
			ret = ft_strdup("-inf");
		//else if (data->plus_sign)
			//ret = ft_strdup("+inf");
		//else if (data->space)
			//ret = ft_strdup(" inf");
		else
			ret = ft_strdup("inf");
	}
	//else if (mant != 0 && data->plus_sign)
	//	ret = ft_strdup("+nan");
	else if (mant != 0)// && !data->plus_sign)
		ret = ft_strdup("nan");
	//else
		//return (0);
	//float_put_naninf(data, ret);
	return (ret);
}

void	print_start_f(t_params *data)
{
	long double	arg;
	char		*output;

	output = NULL;
	if (data->size == 5)
		arg = va_arg(data->args, long double);
	else
		arg = va_arg(data->args, double);
	if (arg < -LDBL_MAX || arg > LDBL_MAX)
		output = floatld_inf_or_nan(0, (arg < 0 ? 1 : 0));
	else if (arg != arg)
		output = floatld_inf_or_nan(1, 0);
	if (output == NULL)
		print_f(data, arg);
	else
	{
		output = use_flag(data, output, 0);
		ft_putstr(output);
		data->total += ft_strlen(output);
	}
}
