/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 23:41:26 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:24:47 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	start_point(char const *s)
{
	int i;

	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	return (i);
}

static int	end_point(char const *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*t;

	if (!s)
		return (NULL);
	start = start_point(s);
	end = end_point(s);
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
