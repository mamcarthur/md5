/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:57:23 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:35:49 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_p(t_cflag cf, t_lmod lm, va_list *argptr)
{
	intptr_t	p;
	int			i;
	size_t		fwdent;

	p = va_arg(*argptr, long long);
	i = 0;
	(void)lm;
	fwdent = ft_baseintlength(p, 16, 0) + 2;
	printwhitespace(&cf, fwdent, ' ');
	pfputstr("0x");
	lm.ll = 1;
	ft_printhex(p, 0, lm);
	printwhitespace(&cf, fwdent, ' ');
}
