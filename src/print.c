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

void		output_with_flags(t_params *data)
{
	// if (data->space == 1)
	// 	print_with_space(data);
	// if (data->hash == 1)
	// 	print_with_hash(data);
	if (data->zero == 1)
		print_with_zero(data);
	if (data->plus_sign == 1)
		print_with_plus(data);
	if (data->minus_sign == 1)
		print_with_minus(data);











	// if (data->width != 0) // сделать последовательный вывод сначала флаги, затем ширина и т.д.
	// {
	// 	if (data->minus_sign != 0)
	// 	{
	// 		print_output(data);
	// 		print_with_width(data);
	// 	}
	// 	else
	// 	{
	// 		print_with_width(data);
	// 		print_output(data);
	// 	}
	// }
	// else
	// 	print_output(data);
}

void		print_integer(t_params *data)
{
	data->output_str = ft_itoa(va_arg(data->args, int));
	output_with_flags(data);
}