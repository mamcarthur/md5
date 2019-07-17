/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:54:24 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:37:20 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_s(t_cflag cf, t_lmod lm, va_list *argptr)
{
	char	*c;
	int		i;
	size_t	fwdent;

	c = va_arg(*argptr, char *);
	if (c == NULL)
		c = "(null)";
	i = 0;
	(void)lm;
	fwdent = ft_strlen(c);
	printwhitespace(&cf, fwdent, ' ');
	pfputstr(c);
	printwhitespace(&cf, fwdent, ' ');
}
