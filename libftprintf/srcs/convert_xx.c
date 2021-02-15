/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 00:55:28 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:24:19 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_xx(t_cflag cf, t_lmod lm, va_list *argptr)
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
		pfputstr("0X");
	ft_xprint('0', cf.pr - ft_baseintlength(x, 16, 0));
	ft_printhex(x, 1, lm);
	printwhitespace(&cf, fwdent, c);
}
