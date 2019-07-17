/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:02:01 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:33:09 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int index;
	unsigned int index_match;

	if (to_find[0] == '\0')
		return (str);
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == to_find[0])
		{
			index_match = 1;
			while (to_find[index_match] == str[index + index_match] &&
					to_find[index_match] != '\0')
				index_match++;
			if (to_find[index_match] == '\0')
				return (&str[index]);
		}
		index++;
	}
	return (0);
}
