/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 23:24:29 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:14:51 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha512.h"

__uint128_t	swap128_endianness(__uint128_t x)
{
	int			i;
	int			j;
	char		k;
	__uint128_t	*y;

	i = 0;
	j = 15;
	y = malloc(sizeof(__uint128_t));
	*y = x;
	while (i < j)
	{
		k = ((char *)(y))[j];
		((char *)(y))[j] = ((char *)(y))[i];
		((char *)(y))[i] = k;
		i++;
		j--;
	}
	x = *y;
	free(y);
	return (x);
}

void		process_w_512(char *message, u_int64_t w[80])
{
	int			i;
	u_int64_t	s0;
	u_int64_t	s1;

	i = 0;
	while (i < 16)
	{
		w[i] = swap64_endianness(((u_int64_t *)(message))[i]);
		i++;
	}
	while (i < 80)
	{
		s0 = rrot64(w[i - 15], 1) ^ rrot64(w[i - 15], 8) ^ (w[i - 15] >> 7);
		s1 = rrot64(w[i - 2], 19) ^ rrot64(w[i - 2], 61) ^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void		ft_sha512_core(u_int64_t w[80], u_int64_t state[8])
{
	u_int64_t	p_state[8];
	int			i;
	u_int64_t	mids[6];

	primestatecpy64(state, p_state);
	i = 0;
	while (i < 80)
	{
		mids[S1] = (rrot64(p_state[E], 14) ^ rrot64(p_state[E], 18)
				^ rrot64(p_state[E], 41));
		mids[CH] = (p_state[E] & p_state[F]) ^ ((~p_state[E]) & p_state[G]);
		mids[TEMP1] = p_state[H] + mids[S1] + mids[CH] + g_sha512k[i] + w[i];
		mids[S0] = rrot64(p_state[A], 28) ^ rrot64(p_state[A], 34) ^
			rrot64(p_state[A], 39);
		mids[MAJ] = (p_state[A] & p_state[B]) ^ (p_state[A] & p_state[C])
			^ (p_state[B] & p_state[C]);
		mids[TEMP2] = mids[S0] + mids[MAJ];
		sha512_state_shuffle(p_state, mids);
		i++;
	}
	state_plus_pstate64(state, p_state);
}

void		ft_sha512(char *str)
{
	size_t		chunks;
	size_t		i;
	char		input1024[128];
	u_int64_t	state[8];
	u_int64_t	w[80];

	chunks = sha512_padding(&str);
	sha512_hash_init(state);
	i = 0;
	while (i < chunks)
	{
		ft_unsafe_strncpy(input1024, str + (i * 128), 128);
		process_w_512(input1024, w);
		ft_sha512_core(w, state);
		i++;
	}
	free(str);
	i = -1;
	while (++i < 16)
	{
		if (i % 2)
			ft_printf("%08x", ((u_int32_t *)(state))[i - 1]);
		else
			ft_printf("%08x", ((u_int32_t *)(state))[i + 1]);
	}
}
