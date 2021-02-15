/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:57:50 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:43:10 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	grabflags(const char *str, t_cflag *cf)
{
	int i;

	i = -1;
	while (str[++i])
	{
		cf->pound += (str[i] == '#' && !cf->pound) ? 1 : 0;
		cf->dash += (str[i] == '-' && !cf->dash) ? 1 : 0;
		cf->plus += (str[i] == '+' && !cf->plus) ? 1 : 0;
		cf->space += (str[i] == ' ' && !cf->space) ? 1 : 0;
		cf->zero += (str[i] == '0' && !cf->zero) ? 1 : 0;
		if (str[i] == '.')
		{
			i++;
			cf->pr = 0;
			while (ft_isdigit(str[i]))
				cf->pr = (cf->pr * 10) + str[i++] - '0';
		}
		else if (ft_isdigit(str[i]) && !cf->fw)
		{
			while (ft_isdigit(str[i]))
				cf->fw = (cf->fw * 10) + str[i++] - '0';
			i--;
		}
	}
	cf->zero -= (cf->zero && cf->dash) ? cf->zero : 0;
}

void	printarg(char cs, t_cflag cf, t_lmod lm, va_list *argptr)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if ((g_cstable[i]).cs == cs)
		{
			(g_cstable[i]).conv(cf, lm, argptr);
			break ;
		}
		i++;
	}
}

int		processflag(const char *str, int i, va_list *argptr)
{
	char		*cflag;
	int			end_flag;
	t_cflag		cf;
	t_lmod		lm;
	int			r;

	end_flag = i + 1;
	while (!ALL_CS(str[end_flag]))
		end_flag++;
	cflag = ft_strsub(str, i + 1, end_flag - i);
	if (cflag[0] == '%')
	{
		ft_writecount(cflag[0]);
		return (1);
	}
	ft_bzero(&cf, sizeof(cf));
	ft_bzero(&lm, sizeof(lm));
	cf.pr = -1;
	grabflags(cflag, &cf);
	grablengthmod(cflag, &lm);
	r = ft_strlen(cflag);
	printarg(cflag[r - 1], cf, lm, argptr);
	free(cflag);
	return (r);
}

int		ft_printf(const char *str, ...)
{
	size_t	i;
	va_list argptr;
	size_t	strl;

	i = 0;
	g_writecount = 0;
	va_start(argptr, str);
	strl = ft_strlen(str);
	while (i < strl)
	{
		if (str[i] == '%')
			i += processflag(str, i, &argptr);
		else
			ft_writecount(str[i]);
		i++;
	}
	return (g_writecount);
}
