/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:39:31 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:51:19 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha256.h"

void	sha256_string_readout(t_hashset h)
{
	char	*str;
	int		fd;

	if (h.s && h.arg_input)
		str = h.arg_input;
	else if (h.arg_input)
	{
		fd = ft_safe_open(h.arg_input, O_RDONLY, "SHA256");
		if (fd < 0)
			return ;
		str = filedump(fd);
	}
	else if (h.s)
	{
		ft_s_no_arg();
		return ;
	}
	else
		str = filedump(0);
	preprint(h, str, "SHA256");
	ft_sha256(str);
	postprint(h);
}

void	run_sha256(int ac, char **av)
{
	t_hashset	*h;
	t_hashset	*f;

	h = hash_build_list(ac, av);
	while (h)
	{
		sha256_string_readout(*h);
		f = h;
		h = h->next;
		free(f);
	}
}
