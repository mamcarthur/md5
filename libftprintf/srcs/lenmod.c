/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:04:22 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/04/11 00:14:55 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	grablengthmod(const char *str, t_lmod *lm)
{
	int i;

	i = -1;
	ft_bzero(lm, sizeof(lm));
	while (str[++i])
	{
		lm->ll = (str[i] == 'l' && str[i + 1] == 'l') ? 1 : lm->ll;
		lm->l = (str[i] == 'l' && lm->ll == 0) ? 1 : lm->l;
		lm->dl = (str[i] == 'L') ? 1 : lm->dl;
		lm->hh = (str[i] == 'h' && str[i + 1] == 'h') ? 1 : lm->hh;
		lm->h = (str[i] == 'h' && lm->hh == 0) ? 1 : lm->hh;
	}
}
