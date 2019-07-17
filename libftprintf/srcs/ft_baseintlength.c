/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseintlength.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:19:01 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:13:38 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_baseintlength(long long n, int base, int s_us)
{
	int i;

	i = 1;
	if (s_us == 0)
		n = (unsigned long long)n;
	while (n >= base || n <= -base)
	{
		i++;
		n /= base;
	}
	return (i);
}
