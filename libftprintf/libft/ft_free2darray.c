/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:33:31 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/09 20:34:40 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_free2darray(char ***array, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(*array[i]);
		i++;
	}
	free(*array);
}
