/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:38:15 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:39:38 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pfputstr(char *c)
{
	int i;

	i = 0;
	while (c[i])
		ft_writecount(c[i++]);
}

void	ft_xprint(char c, int d)
{
	while (d > 0)
	{
		ft_writecount(c);
		d--;
	}
}

void	printsign(t_cflag *cf, long long d)
{
	if (cf->zero)
	{
		if (d < 0)
			ft_writecount('-');
		else if (cf->plus)
			ft_writecount('+');
		else if (cf->space)
			ft_writecount(' ');
	}
	cf->zero = !(cf->zero);
}

void	printwhitespace(t_cflag *cf, size_t length, char c)
{
	int i;

	i = 0;
	if (cf->pr >= 0)
		c = ' ';
	if (!cf->dash)
		while (i++ < ((signed long)cf->fw - (signed long)length))
			ft_writecount(c);
	cf->dash = !(cf->dash);
}
