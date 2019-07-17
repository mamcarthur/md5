/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffgghhii_singles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:39:16 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:27:29 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/md5.h"

void	md5_single_ff(u_int32_t *abcd, t_0123 *order, u_int32_t m, int i)
{
	u_int32_t	xa;
	u_int32_t	xb;
	u_int32_t	xc;
	u_int32_t	xd;
	u_int32_t	inter;

	xa = abcd[order->num];
	xb = abcd[order->next->num];
	xc = abcd[order->next->next->num];
	xd = abcd[order->next->next->next->num];
	inter = (xa + F(xb, xc, xd) + m + g_md5k[i]);
	inter = (inter << g_md5s[i]) | (inter >> (32 - g_md5s[i]));
	inter += xb;
	abcd[order->num] = inter;
}

void	md5_single_gg(u_int32_t *abcd, t_0123 *order, u_int32_t m, int i)
{
	u_int32_t	xa;
	u_int32_t	xb;
	u_int32_t	xc;
	u_int32_t	xd;
	u_int32_t	inter;

	xa = abcd[order->num];
	xb = abcd[order->next->num];
	xc = abcd[order->next->next->num];
	xd = abcd[order->next->next->next->num];
	inter = (xa + G(xb, xc, xd) + m + g_md5k[i]);
	inter = (inter << g_md5s[i]) | (inter >> (32 - g_md5s[i]));
	inter += xb;
	abcd[order->num] = inter;
}

void	md5_single_hh(u_int32_t *abcd, t_0123 *order, u_int32_t m, int i)
{
	u_int32_t	xa;
	u_int32_t	xb;
	u_int32_t	xc;
	u_int32_t	xd;
	u_int32_t	inter;

	xa = abcd[order->num];
	xb = abcd[order->next->num];
	xc = abcd[order->next->next->num];
	xd = abcd[order->next->next->next->num];
	inter = (xa + H(xb, xc, xd) + m + g_md5k[i]);
	inter = (inter << g_md5s[i]) | (inter >> (32 - g_md5s[i]));
	inter += xb;
	abcd[order->num] = inter;
}

void	md5_single_ii(u_int32_t *abcd, t_0123 *order, u_int32_t m, int i)
{
	u_int32_t	xa;
	u_int32_t	xb;
	u_int32_t	xc;
	u_int32_t	xd;
	u_int32_t	inter;

	xa = abcd[order->num];
	xb = abcd[order->next->num];
	xc = abcd[order->next->next->num];
	xd = abcd[order->next->next->next->num];
	inter = (xa + I(xb, xc, xd) + m + g_md5k[i]);
	inter = (inter << g_md5s[i]) | (inter >> (32 - g_md5s[i]));
	inter += xb;
	abcd[order->num] = inter;
}
