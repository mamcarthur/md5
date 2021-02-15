/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:32:21 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 20:43:56 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>
# define CS1(A)	(A == 'd' || A == 'i' || A == 'o' || A == 'u' || A == 'x')
# define CS2(A)	(A == 'X' || A == 'f' || A == 'c' || A == 's' || A == 'p')
# define ALL_CS(A)	(CS1(A) || CS2(A) || A == '%')

typedef	struct		s_cflag
{
	int				pound;
	int				zero;
	int				dash;
	int				plus;
	int				space;
	int				fw;
	int				pr;
}					t_cflag;

typedef struct		s_lmod
{
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				dl;
}					t_lmod;

typedef struct		s_dispatch
{
	char			cs;
	void			(*conv)(t_cflag, t_lmod, va_list *);
}					t_dispatch;

int					ft_baseintlength(long long n, int base, int s_us);
char				adj_len_mod(long long n, t_lmod lm);
void				convert_c(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_d(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_p(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_s(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_o(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_u(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_x(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_xx(t_cflag cf, t_lmod lm, va_list *argptr);
void				convert_f(t_cflag cf, t_lmod lm, va_list *argptr);
void				countputnbr(long long n, t_lmod lm);
long double			float_lenmod(double f, t_lmod lm);
int					get_float_fwdent(t_cflag cf, double f);
long double			ft_absval_float(long double f);
void				ft_putfloat(long double f, t_cflag cf, t_lmod lm);
long long			ft_absval_int(long long d);
int					ft_printf(const char *str, ...);
void				ft_printhex(unsigned long long p, int lc, t_lmod lm);
void				ft_printoctal(unsigned long long o, t_lmod lm);
void				printunsigned(unsigned long long u, t_lmod lm);
void				ft_writecount(char c);
void				ft_xprint(char c, int d);
int					get_int_fwdent(t_cflag cf, int d, int base, int s_us);
void				grabflags(const char *str, t_cflag *cf);
void				grablengthmod(const char *str, t_lmod *lm);
void				pfputstr(char *c);
void				printarg(char cs, t_cflag cf, t_lmod lm, va_list *argptr);
void				printsign(t_cflag *cf, long long d);
void				printwhitespace(t_cflag *cf, size_t length, char c);
int					processflag(const char *str, int i, va_list *argptr);
int					get_u_fwdent(t_cflag cf, unsigned long long d, int base);
size_t				unsigned_hex_length(size_t x);
size_t				hex_dent(t_cflag cf, size_t x);
extern	t_dispatch	g_cstable[];
extern	int			g_writecount;

#endif
