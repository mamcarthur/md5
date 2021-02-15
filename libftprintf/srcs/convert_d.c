/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:52:21 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:19:49 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_absval_int(long long d)
{
	if (d < 0)
		d /= -1;
	return (d);
}

int			get_int_fwdent(t_cflag cf, int d, int base, int s_us)
{
	int i;
	int k;

	i = ft_baseintlength(d, base, s_us);
	k = i;
	if (d < 0 || cf.plus || cf.space)
		k++;
	if (cf.pr && cf.pr <= i && cf.pound)
		k++;
	while (cf.pr - i > 0)
	{
		k++;
		cf.pr--;
	}
	return (k);
}

void		convert_d(t_cflag cf, t_lmod lm, va_list *argptr)
{
	long long	d;
	size_t		fwdent;
	char		c;

	if (lm.hh)
		d = (char)(va_arg(*argptr, int));
	else if (lm.h)
		d = (short)va_arg(*argptr, int);
	else if (lm.l)
		d = (long)va_arg(*argptr, long);
	else if (lm.ll)
		d = (long long)va_arg(*argptr, long long);
	else
		d = (int)va_arg(*argptr, int);
	fwdent = get_int_fwdent(cf, d, 10, 1);
	c = (cf.zero) ? '0' : ' ';
	printsign(&cf, d);
	printwhitespace(&cf, fwdent, c);
	printsign(&cf, d);
	ft_xprint('0', cf.pr - ft_baseintlength(d, 10, 1));
	countputnbr(d, lm);
	printwhitespace(&cf, fwdent, c);
}
