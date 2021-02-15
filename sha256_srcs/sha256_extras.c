/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:40:38 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:53:23 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha256.h"

void		sha256_hash_init(u_int32_t *state)
{
	state[0] = 0x6a09e667;
	state[1] = 0xbb67ae85;
	state[2] = 0x3c6ef372;
	state[3] = 0xa54ff53a;
	state[4] = 0x510e527f;
	state[5] = 0x9b05688c;
	state[6] = 0x1f83d9ab;
	state[7] = 0x5be0cd19;
}

void		primestatecpy(u_int32_t state[8], u_int32_t p_state[8])
{
	p_state[0] = state[0];
	p_state[1] = state[1];
	p_state[2] = state[2];
	p_state[3] = state[3];
	p_state[4] = state[4];
	p_state[5] = state[5];
	p_state[6] = state[6];
	p_state[7] = state[7];
}

void		sha256_state_shuffle(u_int32_t pstate[8], u_int32_t mids[6])
{
	pstate[H] = pstate[G];
	pstate[G] = pstate[F];
	pstate[F] = pstate[E];
	pstate[E] = pstate[D] + mids[TEMP1];
	pstate[D] = pstate[C];
	pstate[C] = pstate[B];
	pstate[B] = pstate[A];
	pstate[A] = mids[TEMP1] + mids[TEMP2];
}

void		state_plus_pstate(u_int32_t state[8], u_int32_t pstate[8])
{
	state[0] += pstate[0];
	state[1] += pstate[1];
	state[2] += pstate[2];
	state[3] += pstate[3];
	state[4] += pstate[4];
	state[5] += pstate[5];
	state[6] += pstate[6];
	state[7] += pstate[7];
}

u_int32_t	rrot(u_int32_t x, u_int32_t y)
{
	return ((x >> y) | (x << (32 - y)));
}
