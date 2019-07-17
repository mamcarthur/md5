/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:05:41 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:07:59 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha512.h"

u_int64_t	rrot64(u_int64_t x, u_int64_t y)
{
	return ((x >> y) | (x << (64 - y)));
}

void		sha512_hash_init(u_int64_t *state)
{
	state[0] = 0x6a09e667f3bcc908;
	state[1] = 0xbb67ae8584caa73b;
	state[2] = 0x3c6ef372fe94f82b;
	state[3] = 0xa54ff53a5f1d36f1;
	state[4] = 0x510e527fade682d1;
	state[5] = 0x9b05688c2b3e6c1f;
	state[6] = 0x1f83d9abfb41bd6b;
	state[7] = 0x5be0cd19137e2179;
}

void		primestatecpy64(u_int64_t state[8], u_int64_t p_state[8])
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

void		sha512_state_shuffle(u_int64_t pstate[8], u_int64_t mids[6])
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

void		state_plus_pstate64(u_int64_t state[8], u_int64_t pstate[8])
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
