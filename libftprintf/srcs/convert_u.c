/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 00:14:14 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:22:47 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_u_fwdent(t_cflag cf, unsigned long long d, int base)
{
	int i;
	int k;

	i = ft_baseintlength(d, base, 0);
	k = i;
	if (cf.pound && base == 8)
		k++;
	while (cf.pr - i > 0)
	{
		k++;
		cf.pr--;
	}
	return (k);
}

void	convert_u(t_cflag cf, t_lmod lm, va_list *argptr)
{
	unsigned long long	u;
	size_t				fwdent;
	char				c;

	u = (unsigned long long)va_arg(*argptr, long long);
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
	fwdent = get_u_fwdent(cf, u, 10);
	c = (cf.zero) ? '0' : ' ';
	printwhitespace(&cf, fwdent, c);
	ft_xprint('0', cf.pr - ft_baseintlength(u, 10, 0));
	printunsigned(u, lm);
	printwhitespace(&cf, fwdent, c);
}
