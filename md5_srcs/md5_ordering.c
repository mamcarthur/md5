/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_ordering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:29:51 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:30:40 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	free_circular(t_0123 *ptr)
{
	free(ptr->next->next->next);
	free(ptr->next->next);
	free(ptr->next);
	free(ptr);
}

t_0123	*init_abcd_ordering(void)
{
	t_0123	*x;
	t_0123	*x_zero;
	int		i;

	i = 0;
	x = malloc(sizeof(t_0123));
	x_zero = x;
	while (i < 3)
	{
		x->num = i++;
		x->next = malloc(sizeof(t_0123));
		x = x->next;
	}
	x->num = i;
	x->next = x_zero;
	x = x->next;
	return (x);
}
