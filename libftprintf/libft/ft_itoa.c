/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:52:46 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:25:42 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	size_calc(int n)
{
	int i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	sign_check(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static void	handle_min_value(char *asc, int *n, int *minval)
{
	asc[0] = '-';
	asc[1] = '2';
	*n = -147483648;
	*minval = 1;
}

char		*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		minval;
	char	*asc;

	len = size_calc(n);
	sign = sign_check(n);
	minval = 0;
	if (!(asc = malloc(sign + len + 1)))
		return (NULL);
	if (n == -2147483648)
		handle_min_value(asc, &n, &minval);
	asc[0] = sign ? '-' : 0;
	n = sign ? n * -1 : n * 1;
	asc[len + sign] = '\0';
	len--;
	while (len - minval >= 0)
	{
		asc[len + sign] = ((n % 10) + '0');
		n /= 10;
		len--;
	}
	return (asc);
}
