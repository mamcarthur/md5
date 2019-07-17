/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:51:05 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:18:55 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while (IS_SPACE(*str) || MORE_SPACES(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i * sign);
}
