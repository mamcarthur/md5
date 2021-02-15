/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:12:26 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 18:31:16 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char	*filedump(int fd)
{
	int		ret;
	char	*buf;
	char	*wholething;
	char	*tmp;

	ret = 1;
	buf = ft_memalloc(sizeof(char) * 1001);
	wholething = ft_strnew(1);
	while ((ret = read(fd, buf, 1000)))
	{
		buf[ret] = 0;
		tmp = wholething;
		wholething = ft_strjoin(wholething, buf);
		free(tmp);
		tmp = NULL;
	}
	free(buf);
	return (wholething);
}

int		ft_safe_open(char *s, int flag, char *fctn)
{
	int	fd;
	int fd2;

	fd = open(s, flag);
	if (((fd2 = open(s, O_WRONLY)) < 0) && errno == EISDIR)
	{
		ft_printf("ft_ssl: %s: %s: Is a directory\n", fctn, s);
		return (-1);
	}
	else if (fd < 0)
		ft_printf("ft_ssl: %s: %s: No such file or directory\n", fctn, s);
	return (fd);
}

void	md5_string_readout(t_hashset h)
{
	char	*str;
	int		fd;

	if (h.s && h.arg_input)
		str = h.arg_input;
	else if (h.arg_input)
	{
		fd = ft_safe_open(h.arg_input, O_RDONLY, "md5");
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
	preprint(h, str, "MD5");
	ft_md5(str);
	postprint(h);
}

void	run_md5(int ac, char **av)
{
	t_hashset	*h;
	t_hashset	*f;

	h = hash_build_list(ac, av);
	while (h)
	{
		md5_string_readout(*h);
		f = h;
		h = h->next;
		free(f);
	}
}
