/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:18:17 by rmonserr          #+#    #+#             */
/*   Updated: 2019/09/18 14:18:18 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
		ft_memdel((void **)as);
}
