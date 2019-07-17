/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 00:36:33 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:24:40 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		unsigned_hex_length(size_t x)
{
	int i;

	i = 1;
	while (x >= 16)
	{
		x /= 16;
		i++;
	}
	return (i);
}

size_t		hex_dent(t_cflag cf, size_t x)
{
	int i;
	int k;

	i = unsigned_hex_length(x);
	k = i;
	while (cf.pr - i > 0)
	{
		k++;
		cf.pr--;
	}
	return (k);
}

void		convert_x(t_cflag cf, t_lmod lm, va_list *argptr)
{
	unsigned int	x;
	size_t			fwdent;
	char			c;
	int				alt;

	x = (unsigned)va_arg(*argptr, int);
	if (lm.hh)
		x = (unsigned char)x;
	else if (lm.h)
		x = (unsigned short)x;
	else if (lm.l)
		x = (unsigned long)x;
	else if (lm.ll)
		x = (unsigned long long)x;
	alt = (cf.pound) ? 2 : 0;
	fwdent = hex_dent(cf, x) + alt;
	c = (cf.zero) ? '0' : ' ';
	printwhitespace(&cf, fwdent, c);
	if (cf.pound)
		pfputstr("0x");
	ft_xprint('0', cf.pr - ft_baseintlength(x, 16, 0));
	ft_printhex(x, 0, lm);
	printwhitespace(&cf, fwdent, c);
}
