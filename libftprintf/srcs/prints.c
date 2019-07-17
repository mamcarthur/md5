/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:45:16 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:40:03 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_writecount(char c)
{
	write(1, &c, 1);
	g_writecount++;
}

void	ft_printhex(unsigned long long p, int lc, t_lmod lm)
{
	char c;
	char a;

	if (lm.hh)
		p = (unsigned char)p;
	else if (lm.h)
		p = (unsigned short)p;
	else if (lm.l)
		p = (unsigned long)p;
	else if (lm.ll)
		p = (unsigned long long)p;
	else
		p = (unsigned int)p;
	if (lc)
		a = 'A';
	else
		a = 'a';
	if (p >= 16)
		ft_printhex(p / 16, lc, lm);
	c = ((p % 16) < 10 ? (p % 16) + '0' : a + (p % 16) - 10);
	ft_writecount(c);
}

void	printunsigned(unsigned long long u, t_lmod lm)
{
	char c;

	if (lm.hh)
		u = (unsigned char)u;
	else if (lm.h)
		u = (unsigned short)u;
	else if (lm.l)
		u = (unsigned long)u;
	else if (lm.ll)
		u = (unsigned long long)u;
	else
		u = (unsigned int)u;
	if (u >= 10)
		printunsigned(u / 10, lm);
	c = (u % 10) + '0';
	ft_writecount(c);
}

void	ft_printoctal(unsigned long long o, t_lmod lm)
{
	char c;

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
	if (o >= 8)
		ft_printoctal(o / 8, lm);
	c = (o % 8) + '0';
	ft_writecount(c);
}

void	countputnbr(long long n, t_lmod lm)
{
	if (lm.hh)
		n = (char)n;
	else if (lm.h)
		n = (short)n;
	else if (lm.l)
		n = (long)n;
	else if (lm.ll)
		n = (long long)n;
	else
		n = (int)n;
	if (n < 10 && n >= 0)
		ft_writecount(n + '0');
	else if (n > -10 && n <= 0)
		ft_writecount(-n + '0');
	else
	{
		countputnbr(n / 10, lm);
		countputnbr(n % 10, lm);
	}
}
