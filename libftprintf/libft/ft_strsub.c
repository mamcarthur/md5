/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 23:05:55 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:29:20 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	t = malloc(len + 1);
	if (!t || !s)
		return (NULL);
	s += start;
	i = 0;
	while (i < len)
	{
		*(t + i) = *(s + i);
		i++;
	}
	*(t + i) = '\0';
	return (t);
}
