/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:46:52 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:23:40 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double		ft_absval_float(long double f)
{
	if (f < 0)
		f *= -1;
	return (f);
}

int				get_float_fwdent(t_cflag cf, double f)
{
	int length;

	length = ft_baseintlength((unsigned long long)f, 10, 1);
	length += (cf.pr < 0) ? 6 : cf.pr;
	length += (cf.pr == 0 && !cf.pound) ? 0 : 1;
	return (length);
}

long double		float_lenmod(double f, t_lmod lm)
{
	if (lm.l)
		return ((double)f);
	else if (lm.dl)
		return ((long double)f);
	else
		return ((float)f);
}

void			ft_putfloat(long double f, t_cflag cf, t_lmod lm)
{
	long long unsigned	wholenum;
	int					i;

	if (lm.l)
		f = (double)f;
	else if (lm.dl)
		f = (long double)f;
	else
		f = (float)f;
	wholenum = (long long unsigned int)f;
	countputnbr(wholenum, lm);
	if (cf.pr || !cf.pound)
		ft_writecount('.');
	i = 0;
	if (cf.pr < 0)
		cf.pr = 6;
	f -= wholenum;
	while (i < cf.pr)
	{
		f *= 10;
		wholenum = (long long unsigned int)f;
		ft_writecount(wholenum % 10 + '0');
		i++;
		f -= wholenum;
	}
}

void			convert_f(t_cflag cf, t_lmod lm, va_list *argptr)
{
	long double	f;
	size_t		fwdent;
	char		c;

	if (lm.l)
		f = va_arg(*argptr, double);
	else if (lm.dl)
		f = (long double)va_arg(*argptr, double);
	else
		f = (float)va_arg(*argptr, double);
	fwdent = get_float_fwdent(cf, f);
	c = (cf.zero) ? '0' : ' ';
	printsign(&cf, (int)f);
	printwhitespace(&cf, fwdent, c);
	printsign(&cf, (int)f);
	ft_putfloat(ft_absval_float(f), cf, lm);
	printwhitespace(&cf, fwdent, c);
}
