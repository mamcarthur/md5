/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_build_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:06:22 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/20 20:35:34 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

t_hashset	*ft_hashset_init(void)
{
	t_hashset	*h;

	h = malloc(sizeof(t_hashset));
	ft_bzero(h, sizeof(*h));
	return (h);
}

int			ft_ismd5flag(char *str)
{
	int x;

	x = 1;
	if (ft_strequ(str, "-p"))
		return (1);
	if (ft_strequ(str, "-q"))
		return (1);
	if (ft_strequ(str, "-r"))
		return (1);
	if (ft_strequ(str, "-s"))
		return (1);
	return (0);
}

int			md5fillstruct(t_hashset *h, int ac, char **av, int *i)
{
	while (*i < ac)
	{
		ft_ismd5flag(av[*i]);
		if (ft_strequ("-p", av[*i]) || ft_strequ("-s", av[*i]) ||
			!ft_ismd5flag(av[*i]))
		{
			h->p = (ft_strequ("-p", av[*i])) ? 1 : 0;
			h->s = (ft_strequ("-s", av[*i])) ? 1 : 0;
			*i += (ft_strequ("-s", av[*i])) ? 1 : 0;
			if (!ft_ismd5flag(av[*i]) || ft_strequ("-s", av[*i]))
				h->arg_input = av[*i];
			return (++(*i));
		}
		if (ft_strequ("-q", av[*i]) || ft_strequ("-r", av[*i]))
		{
			h->q = (ft_strequ("-q", av[*i])) ? 1 : 0;
			h->r = (ft_strequ("-r", av[*i])) ? 1 : 0;
		}
		(*i)++;
	}
	return (*i);
}

t_hashset	*hash_build_list(int ac, char **av)
{
	int			i;
	t_hashset	*lst_ptr;
	t_hashset	*tmp;

	lst_ptr = ft_hashset_init();
	tmp = lst_ptr;
	i = 2;
	md5fillstruct(tmp, ac, av, &i);
	while (i < ac)
	{
		tmp->next = ft_hashset_init();
		tmp = tmp->next;
		i += md5fillstruct(tmp, ac, av, &i);
	}
	return (lst_ptr);
}
