/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:53:35 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:24:19 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	start_point(char const *s, char c)
{
	int i;

	i = 0;
	while (*(s + i) == c)
		i++;
	return (i);
}

static int	end_point(char const *s, char c)
{
	int i;

	i = ft_strlen(s) - 1;
	while (*(s + i) == c)
		i--;
	return (i);
}

char		*ft_strctrim(char const *s, char c)
{
	int		start;
	int		end;
	int		i;
	char	*t;

	if (!s)
		return (NULL);
	start = start_point(s, c);
	end = end_point(s, c);
	if (start < end)
		t = malloc(end - start + 2);
	else
		t = malloc(1);
	if (!t)
		return (NULL);
	i = 0;
	while (i <= end - start)
	{
		t[i] = s[start + i];
		i++;
	}
	t[i] = 0;
	return (t);
}
