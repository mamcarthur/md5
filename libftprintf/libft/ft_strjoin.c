/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 23:23:59 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:29:14 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *t;

	if (!s1 || !s2)
		return (NULL);
	t = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!t)
		return (NULL);
	t = ft_strcpy(t, (char *)s1);
	t = ft_strcat(t, (char *)s2);
	return (t);
}
