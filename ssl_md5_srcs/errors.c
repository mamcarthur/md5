/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:01:29 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 23:57:10 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	ft_show_usage(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	exit(0);
}

void	ft_invalid_command(char *s)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", s);
	ft_printf("Standard commands:\n\n");
	ft_printf("Message Digest commands:\n");
	ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n\n");
	ft_printf("Cipher commands:\n");
	exit(0);
}

void	ft_s_no_arg(void)
{
	ft_printf("md5: option requires an argument --s\n");
	ft_printf("usage: md5 [-pqrtx] [-s string] [fils ...]\n");
	exit(0);
}

void	err_illegal_opt(char c)
{
	ft_printf("md5: illegal option -- %c\n", c);
	ft_printf("usage: md5 [-pqrtx] [-s string] [fils ...]\n");
	exit(0);
}
