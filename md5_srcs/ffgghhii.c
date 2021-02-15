/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffgghhii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:36:24 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:30:45 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/md5.h"

void	md5_ff_rounds(u_int32_t *abcd_internal, u_int32_t *message)
{
	int		i;
	int		j;
	t_0123	*abcd_ordering;

	i = 0;
	j = 0;
	abcd_ordering = init_abcd_ordering();
	while (i < 16)
	{
		md5_single_ff(abcd_internal, abcd_ordering, message[j], i);
		i++;
		j += 1;
		abcd_ordering = abcd_ordering->next->next->next;
	}
	free_circular(abcd_ordering);
}

void	md5_gg_rounds(u_int32_t *abcd_internal, u_int32_t *message)
{
	int		i;
	int		j;
	t_0123	*abcd_ordering;

	i = 16;
	j = 1;
	abcd_ordering = init_abcd_ordering();
	while (i < 32)
	{
		if (j >= 16)
			j -= 16;
		md5_single_gg(abcd_internal, abcd_ordering, message[j], i);
		i++;
		j += 5;
		abcd_ordering = abcd_ordering->next->next->next;
	}
	free_circular(abcd_ordering);
}

void	md5_hh_rounds(u_int32_t *abcd_internal, u_int32_t *message)
{
	int		i;
	int		j;
	t_0123	*abcd_ordering;

	i = 32;
	j = 5;
	abcd_ordering = init_abcd_ordering();
	while (i < 48)
	{
		if (j >= 16)
			j -= 16;
		md5_single_hh(abcd_internal, abcd_ordering, message[j], i);
		i++;
		j += 3;
		abcd_ordering = abcd_ordering->next->next->next;
	}
	free_circular(abcd_ordering);
}

void	md5_ii_rounds(u_int32_t *abcd_internal, u_int32_t *message)
{
	int		i;
	int		j;
	t_0123	*abcd_ordering;

	i = 48;
	j = 0;
	abcd_ordering = init_abcd_ordering();
	while (i < 64)
	{
		if (j >= 16)
			j -= 16;
		md5_single_ii(abcd_internal, abcd_ordering, message[j], i);
		i++;
		j += 7;
		abcd_ordering = abcd_ordering->next->next->next;
	}
	free_circular(abcd_ordering);
}
