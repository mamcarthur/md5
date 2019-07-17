/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspacedwords.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:21:12 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 15:59:38 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_countspacedwords(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (IS_SPACE(*s))
			s++;
		if (!ft_iswhitespace(*s) && *s)
			count++;
		while (!ft_iswhitespace(*s) && *s)
			s++;
	}
	return (count);
}
