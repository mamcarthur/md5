/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:02:16 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:00:49 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha512.h"

__uint128_t	big_strlen(char *str)
{
	__uint128_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

__uint128_t	calc_sha256_padded(char *str)
{
	__uint128_t len;

	len = big_strlen(str);
	len++;
	while (len % (1024 / 8) != (896 / 8))
		len++;
	len += 128 / 8;
	return (len);
}

__uint128_t	sha512_padding(char **str)
{
	char		*padded_input;
	char		*length_pos;
	__uint128_t	*big_len;
	__uint128_t	og_len;
	__uint128_t	full_len;

	og_len = big_strlen(*str);
	full_len = calc_sha256_padded(*str);
	padded_input = ft_memalloc(full_len);
	ft_strcpy(padded_input, *str);
	padded_input[ft_strlen(*str)] = (char)(1 << 7);
	length_pos = padded_input + full_len - 16;
	big_len = (__uint128_t *)(length_pos);
	*big_len = swap128_endianness(og_len * 8);
	*str = padded_input;
	return (full_len / (1024 / 8));
}
