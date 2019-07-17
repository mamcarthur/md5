/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:48:09 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 23:45:07 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ft_direct_commands(int ac, char **av)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (ft_strequ((g_sslcommands[i]).name, av[1]))
		{
			(g_sslcommands[i]).runcomm(ac, av);
			return ;
		}
		i++;
	}
	ft_invalid_command(av[1]);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_show_usage();
	ft_direct_commands(ac, av);
}
