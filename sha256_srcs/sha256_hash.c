/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 21:01:18 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:49:26 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha256.h"

u_int64_t	swap64_endianness(u_int64_t x)
{
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8 | (x & 0xFF00FF00FF00FF00) >> 8;
	return (x);
}

size_t		sha256_padding(char **str)
{
	char		*padded_input;
	char		*length_pos;
	u_int64_t	*len_p_o_s;
	size_t		original_message_length;
	size_t		full_length;

	original_message_length = ft_strlen(*str);
	full_length = calc_md5_padded(*str);
	padded_input = ft_memalloc(full_length);
	ft_strcpy(padded_input, *str);
	padded_input[ft_strlen(*str)] = (char)(1 << 7);
	length_pos = padded_input + full_length - 8;
	len_p_o_s = (u_int64_t *)(length_pos);
	*len_p_o_s = swap64_endianness((u_int64_t)(original_message_length * 8));
	*str = padded_input;
	return (full_length / (512 / 8));
}

void		ft_sha256_core(u_int32_t w[64], u_int32_t state[8])
{
	u_int32_t	p_state[8];
	int			i;
	u_int32_t	mids[6];

	primestatecpy(state, p_state);
	i = 0;
	while (i < 64)
	{
		mids[S1] = (rrot(p_state[E], 6) ^ rrot(p_state[E], 11) ^
				rrot(p_state[E], 25));
		mids[CH] = (p_state[E] & p_state[F]) ^ ((~p_state[E]) & p_state[G]);
		mids[TEMP1] = p_state[H] + mids[S1] + mids[CH] + g_sha256k[i] + w[i];
		mids[S0] = rrot(p_state[A], 2) ^ rrot(p_state[A], 13) ^
			rrot(p_state[A], 22);
		mids[MAJ] = (p_state[A] & p_state[B]) ^ (p_state[A] & p_state[C]) ^
			(p_state[B] & p_state[C]);
		mids[TEMP2] = mids[S0] + mids[MAJ];
		sha256_state_shuffle(p_state, mids);
		i++;
	}
	state_plus_pstate(state, p_state);
}

void		process_w(char *message, u_int32_t w[64])
{
	int			i;
	u_int32_t	s0;
	u_int32_t	s1;

	i = 0;
	while (i < 16)
	{
		w[i] = swap32_endianness(((u_int32_t *)(message))[i]);
		i++;
	}
	while (i < 64)
	{
		s0 = rrot(w[i - 15], 7) ^ rrot(w[i - 15], 18) ^ (w[i - 15] >> 3);
		s1 = rrot(w[i - 2], 17) ^ rrot(w[i - 2], 19) ^ (w[i - 2] >> 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
}

void		ft_sha256(char *str)
{
	size_t		chunks;
	size_t		i;
	char		input512[64];
	u_int32_t	state[8];
	u_int32_t	w[64];

	chunks = sha256_padding(&str);
	sha256_hash_init(state);
	i = 0;
	while (i < chunks)
	{
		ft_unsafe_strncpy(input512, str + (i * 64), 64);
		process_w(input512, w);
		ft_sha256_core(w, state);
		i++;
	}
	free(str);
	i = 0;
	while (i < 8)
		ft_printf("%08x", state[i++]);
}
