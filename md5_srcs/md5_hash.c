/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:10:51 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:28:10 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/md5.h"

/*
** 512, 448, 64 bits are 64, 56, and 8 bytes, respectively
*/

size_t		calc_md5_padded(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	len++;
	while (len % (512 / 8) != (448 / 8))
		len++;
	len += 64 / 8;
	return (len);
}

size_t		md5_padding(char **str)
{
	char		*padded_input;
	char		*length_pos;
	size_t		original_message_length;
	size_t		full_length;
	u_int64_t	*long_len;

	original_message_length = ft_strlen(*str);
	full_length = calc_md5_padded(*str);
	padded_input = ft_memalloc(full_length);
	ft_strcpy(padded_input, *str);
	padded_input[ft_strlen(*str)] = (char)(1 << 7);
	length_pos = padded_input + full_length - 8;
	long_len = (u_int64_t *)length_pos;
	*long_len = (u_int64_t)(original_message_length * 8);
	*str = padded_input;
	return (full_length / (512 / 8));
}

void		ft_md5_core(char *message, u_int32_t *hash)
{
	u_int32_t	abcd_internal[4];

	abcd_internal[0] = hash[0];
	abcd_internal[1] = hash[1];
	abcd_internal[2] = hash[2];
	abcd_internal[3] = hash[3];
	md5_ff_rounds(abcd_internal, (u_int32_t *)message);
	md5_gg_rounds(abcd_internal, (u_int32_t *)message);
	md5_hh_rounds(abcd_internal, (u_int32_t *)message);
	md5_ii_rounds(abcd_internal, (u_int32_t *)message);
	hash[0] += abcd_internal[0];
	hash[1] += abcd_internal[1];
	hash[2] += abcd_internal[2];
	hash[3] += abcd_internal[3];
}

char		*ft_unsafe_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void		ft_md5(char *str)
{
	size_t		chunks;
	size_t		i;
	char		input512[64];
	u_int32_t	hashabcd[4];

	chunks = md5_padding(&str);
	hashabcd[0] = 0x67452301;
	hashabcd[1] = 0xefcdab89;
	hashabcd[2] = 0x98badcfe;
	hashabcd[3] = 0x10325476;
	i = 0;
	while (i < chunks)
	{
		ft_unsafe_strncpy(input512, str + (i * 64), 64);
		ft_md5_core(input512, hashabcd);
		i++;
	}
	free(str);
	i = 0;
	while (i < 4)
		ft_printf("%08x", swap32_endianness(hashabcd[i++]));
}
