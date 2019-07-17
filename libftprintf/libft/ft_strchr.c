/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:30:32 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:31:43 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
