/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:44:18 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:23:09 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_o(t_cflag cf, t_lmod lm, va_list *argptr)
{
	unsigned long	o;
	size_t			fwdent;
	char			c;

	o = (unsigned)va_arg(*argptr, long long);
	if (lm.hh)
		o = (unsigned char)o;
	else if (lm.h)
		o = (unsigned short)o;
	else if (lm.l)
		o = (unsigned long)o;
	else if (lm.ll)
		o = (unsigned long long)o;
	else
		o = (unsigned int)o;
	fwdent = get_u_fwdent(cf, o, 8);
	c = (cf.zero) ? '0' : ' ';
	printwhitespace(&cf, fwdent, c);
	if (cf.pound && (cf.pr <= ft_baseintlength(o, 8, 0)) && o != 0)
		ft_writecount('0');
	ft_xprint('0', cf.pr - ft_baseintlength(o, 8, 0));
	ft_printoctal(o, lm);
	printwhitespace(&cf, fwdent, c);
}
