/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:57:57 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:24:38 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	metastrcpy(char **dst, int wc, const char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < wc)
	{
		k = 0;
		dst[i] = ft_strnew(ft_strclen(s + j, c) + 1);
		if (!dst[i])
			return (0);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			dst[i][k] = s[j];
			k++;
			j++;
		}
		dst[i][k] = 0;
		i++;
	}
	dst[i] = 0;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wordcount;
	char	**dst;
	int		escape;

	if (!s)
		return (NULL);
	wordcount = ft_ccountwords(s, c);
	dst = malloc((8) * (wordcount + 1));
	if (!dst)
		return (NULL);
	escape = metastrcpy(dst, wordcount, s, c);
	if (!escape)
		return (NULL);
	return (dst);
}
