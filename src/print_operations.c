/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:14:20 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/06 17:14:21 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_zeroes(int zero_counter)
{
	int		counter;

	counter = 0;
	while (counter++ != zero_counter)
		ft_putchar('0');
}

void		print_output(t_params *data)
{
	ft_putstr(data->output_str);
}

void		print_spaces(int space_counter)
{
	int		counter;

	counter = 0;
	while (counter++ != space_counter)
		ft_putchar(' ');
}

void		print_with_width(t_params *data)
{
	int		counter;
	int		space_counter;
	int		zero_counter;

	space_counter = 0;
	zero_counter = 0;
	counter = ft_strlen(data->output_str);
	if (data->zero == 1)
	{
		zero_counter = data->width - counter;
		if (zero_counter <= 0)
			return ;
		else
			print_zeroes(zero_counter);
	}
	else
	{
		space_counter = data->width - counter;
		if (space_counter <= 0)
			return ;
		else
			print_spaces(space_counter);
	}

}
