/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:38:21 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:32:06 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	ptrdst = dst;
	ptrsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(ptrdst + i) = *(ptrsrc + i);
		i++;
	}
	return (dst);
}
