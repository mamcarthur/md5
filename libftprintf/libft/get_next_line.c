/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:10:48 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/07 16:15:49 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	string_peeler(char **s, char **line)
{
	char	*str;
	char	*ptr;

	if (ft_strchr(*s, '\n'))
	{
		str = *s;
		ptr = ft_strchr(*s, '\n');
		*ptr = '\0';
		*line = ft_strdup(*s);
		ptr++;
		*s = NULL;
		if (*ptr != '\0')
			*s = ft_strdup(ptr);
		free(str);
		str = NULL;
		ptr = NULL;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *s[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	int			read_out;
	char		*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	while ((read_out = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!s[fd])
			s[fd] = ft_strnew(1);
		buf[read_out] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(s[fd], buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (read_out == 0 && s[fd] == NULL)
		return (0);
	return (string_peeler(&s[fd], line));
}
