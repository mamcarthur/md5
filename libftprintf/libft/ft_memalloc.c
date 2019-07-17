/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:13:59 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:30:24 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*t;
	size_t	i;

	i = size;
	t = malloc(size);
	if (!t)
		return (NULL);
	ft_bzero(t, size);
	return (t);
}
