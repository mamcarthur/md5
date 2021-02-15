/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:39:50 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:35:08 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = (ft_strlen(s1) > ft_strlen(s2) ? ft_strlen(s1) : ft_strlen(s2));
	return (ft_memcmp(s1, s2, i));
}
