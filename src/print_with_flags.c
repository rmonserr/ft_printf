/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:07:15 by rmonserr          #+#    #+#             */
/*   Updated: 2020/07/06 19:07:17 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_with_space(t_params *data)
{

}

void		print_with_hash(t_params *data)
{

}

void		print_with_zero(t_params *data)
{

}

void		print_with_plus(t_params *data)
{
	if (data->plus_sign != 0)
	{
		
	}
}

void		print_with_minus(t_params *data)
{
	if (data->width != 0)
	{
		print_output(data);
		print_with_width(data);
	}
}