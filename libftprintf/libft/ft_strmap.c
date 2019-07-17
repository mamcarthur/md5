/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:50:17 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:30:40 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*t;

	if (!s || !f)
		return (NULL);
	t = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!t)
		return (NULL);
	while (s[i])
	{
		t[i] = f(s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
