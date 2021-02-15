/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:38:04 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/22 16:14:58 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		preprint(t_hashset h, char *str, char *comm)
{
	if ((!h.arg_input && !h.p) || h.q || h.r)
		return ;
	if (h.p)
	{
		ft_printf("%s", str);
		return ;
	}
	ft_printf("%s(", comm);
	if (h.s)
		ft_printf("\"%s\"", h.arg_input);
	else
		ft_printf("%s", realpath(h.arg_input, NULL));
	ft_printf(")= ");
}

void		postprint(t_hashset h)
{
	if (h.r && !h.q)
	{
		if (h.s)
			ft_printf(" \"%s\"", h.arg_input);
		else
			ft_printf("%s", realpath(h.arg_input, NULL));
	}
	ft_printf("\n");
}

u_int32_t	swap32_endianness(u_int32_t n)
{
	u_int32_t	swapped;

	swapped = ((n >> 24) & 0xff) | ((n << 8) & 0xff0000)
		| ((n >> 8) & 0xff00) | ((n << 24) & 0xff000000);
	return (swapped);
}
