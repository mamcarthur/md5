/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:52:32 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/17 13:47:47 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_c(t_cflag cf, t_lmod lm, va_list *argptr)
{
	char	c;
	int		i;

	c = (char)va_arg(*argptr, int);
	i = 0;
	(void)lm;
	printwhitespace(&cf, 1, ' ');
	ft_writecount(c);
	printwhitespace(&cf, 1, ' ');
}
