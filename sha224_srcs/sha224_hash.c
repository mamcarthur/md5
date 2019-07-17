/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 21:01:18 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:36:53 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha256.h"

void	sha224_hash_init(u_int32_t *state)
{
	state[0] = 0xc1059ed8;
	state[1] = 0x367cd507;
	state[2] = 0x3070dd17;
	state[3] = 0xf70e5939;
	state[4] = 0xffc00b31;
	state[5] = 0x68581511;
	state[6] = 0x64f98fa7;
	state[7] = 0xbefa4fa4;
}

void	ft_sha224(char *str)
{
	size_t		chunks;
	size_t		i;
	char		input512[64];
	u_int32_t	state[8];
	u_int32_t	w[64];

	chunks = sha256_padding(&str);
	sha224_hash_init(state);
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
	while (i < 7)
		ft_printf("%08x", state[i++]);
}
