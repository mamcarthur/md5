/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 01:56:26 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 19:55:13 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/sha512.h"

void	sha384_string_readout(t_hashset h)
{
	char	*str;
	int		fd;

	if (h.s && h.arg_input)
		str = h.arg_input;
	else if (h.arg_input)
	{
		fd = ft_safe_open(h.arg_input, O_RDONLY, "SHA384");
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
	preprint(h, str, "SHA384");
	ft_sha384(str);
	postprint(h);
}

void	run_sha384(int ac, char **av)
{
	t_hashset	*h;
	t_hashset	*f;

	h = hash_build_list(ac, av);
	while (h)
	{
		sha384_string_readout(*h);
		f = h;
		h = h->next;
		free(f);
	}
}
