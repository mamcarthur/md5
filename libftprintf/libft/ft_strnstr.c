/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:22:08 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:33:01 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t n)
{
	unsigned int i;
	unsigned int i_match;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	i_match = 0;
	while ((haystack[i] != '\0') && (i < n))
	{
		if (haystack[i] == needle[0])
		{
			i_match = 1;
			while (needle[i_match] == haystack[i + i_match] &&
					needle[i_match] != '\0' &&
					(i + i_match < n))
				i_match++;
			if (needle[i_match] == '\0')
				return (&haystack[i]);
		}
		i++;
	}
	return (0);
}
