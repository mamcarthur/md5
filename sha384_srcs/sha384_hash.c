/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:58:23 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:58:03 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha512.h"

void	sha384_hash_init(u_int64_t *state)
{
	state[0] = 0xcbbb9d5dc1059ed8;
	state[1] = 0x629a292a367cd507;
	state[2] = 0x9159015a3070dd17;
	state[3] = 0x152fecd8f70e5939;
	state[4] = 0x67332667ffc00b31;
	state[5] = 0x8eb44a8768581511;
	state[6] = 0xdb0c2e0d64f98fa7;
	state[7] = 0x47b5481dbefa4fa4;
}

void	ft_sha384(char *str)
{
	size_t		chunks;
	size_t		i;
	char		input1024[128];
	u_int64_t	state[8];
	u_int64_t	w[80];

	chunks = sha512_padding(&str);
	sha384_hash_init(state);
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
	while (++i < 12)
	{
		if (i % 2)
			ft_printf("%08x", ((u_int32_t *)(state))[i - 1]);
		else
			ft_printf("%08x", ((u_int32_t *)(state))[i + 1]);
	}
}
