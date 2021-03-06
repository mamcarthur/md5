/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:10:30 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/27 23:14:24 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long	ft_absval(int k)
{
	if (k < 0)
		k *= -1;
	return (k);
}
