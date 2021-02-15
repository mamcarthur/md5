/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:11:28 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/23 22:52:27 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libftprintf/includes/ft_printf.h"
# include <fcntl.h>
# include <errno.h>

/*
** MACROS
*/

# define ISQRFLAG(A) (A == ft_strequ(A, "-q") || ft_strequ(A, "-r"))
# define ISPSFLAG(A) (A == ft_strequ(A, "-p") || ft_strequ(A, "-s"))
# define IS_FLAG(A) (ISQRFLAG(A) || ISPSFLAG(A))

/*
** TYPEDEF
*/

typedef u_int32_t	t_u32;

typedef u_int64_t	t_u64;

typedef	struct		s_command
{
	char			*name;
	void			(*runcomm)(int, char **);
}					t_command;

typedef	struct		s_hashset
{
	int				p;
	int				q;
	int				r;
	int				s;
	char			*arg_input;
	void			*next;
}					t_hashset;

typedef struct		s_0123
{
	int				num;
	struct s_0123	*next;
}					t_0123;

/*
** GLOBAL VARIABLES
*/

extern t_u32		g_md5s[64];
extern t_u32		g_md5k[64];
extern t_u64		g_sha512k[80];
extern t_u32		g_sha256k[64];
extern t_command	g_sslcommands[];

/*
** *********************************************************************** **
**                              SSL_MD5                                    **
** *********************************************************************** **
*/

void				ft_direct_commands(int ac, char **av);

void				ft_s_no_arg(void);
void				ft_show_usage(void);
void				err_illegal_opt(char c);
void				ft_invalid_command(char *s);

t_hashset			*ft_hashset_init(void);
int					ft_ismd5flag(char *str);
t_hashset			*hash_build_list(int ac, char **av);
int					md5fillstruct(t_hashset *h, int ac, char **av, int *i);

void				postprint(t_hashset h);
void				preprint(t_hashset h, char *str, char *comm);

t_u32				swap32_endianness(t_u32 n);
t_u64				swap64_endianness(t_u64 x);
t_u32				rrot(t_u32 x, t_u32 y);
t_u64				rrot64(t_u64 x, t_u64 y);
__uint128_t			swap128_endianness(__uint128_t x);

/*
** MD5
*/

char				*filedump(int fd);
void				ft_md5(char *str);
size_t				md5_padding(char **str);
t_0123				*init_abcd_ordering(void);
void				run_md5(int ac, char **av);
size_t				calc_md5_padded(char *str);
void				free_circular(t_0123 *ptr);
void				md5_string_readout(t_hashset h);
int					ft_safe_open(char *s, int flag, char *fctn);
void				ft_md5_core(char *message, t_u32 *hash);
char				*ft_unsafe_strncpy(char *dest, const char *src, size_t n);

void				md5_ff_rounds(t_u32 *abcd_internal, t_u32 *message);
void				md5_gg_rounds(t_u32 *abcd_internal, t_u32 *message);
void				md5_hh_rounds(t_u32 *abcd_internal, t_u32 *message);
void				md5_ii_rounds(t_u32 *abcd_internal, t_u32 *message);
void				md5_single_ff(t_u32 *abcd, t_0123 *order, t_u32 m, int i);
void				md5_single_gg(t_u32 *abcd, t_0123 *order, t_u32 m, int i);
void				md5_single_hh(t_u32 *abcd, t_0123 *order, t_u32 m, int i);
void				md5_single_ii(t_u32 *abcd, t_0123 *order, t_u32 m, int i);

/*
** SHA256
*/

void				ft_sha256(char *str);
size_t				sha256_padding(char **str);
void				run_sha256(int ac, char **av);
void				sha256_string_readout(t_hashset h);
void				sha256_hash_init(t_u32 *state);
void				process_w(char *message, t_u32 w[64]);
void				ft_sha256_core(t_u32 w[64], t_u32 state[8]);
void				primestatecpy(t_u32 state[8], t_u32 p_state[8]);
void				state_plus_pstate(t_u32 state[8], t_u32 pstate[8]);
void				sha256_state_shuffle(t_u32 pstate[8], t_u32 mids[6]);

/*
** SHA224
*/

void				ft_sha224(char *str);
void				run_sha224(int ac, char **av);
void				sha224_string_readout(t_hashset h);
void				sha224_hash_init(t_u32 *state);

/*
** SHA384
*/

void				ft_sha384(char *str);
void				run_sha384(int ac, char **av);
void				sha384_string_readout(t_hashset h);
void				sha384_hash_init(t_u64 *state);

/*
** SHA512
*/

void				ft_sha512(char *str);
__uint128_t			big_strlen(char *str);
__uint128_t			sha512_padding(char **str);
void				run_sha512(int ac, char **av);
__uint128_t			calc_sha256_padded(char *str);
void				sha512_string_readout(t_hashset h);
void				sha512_hash_init(t_u64 *state);
void				process_w_512(char *message, t_u64 w[80]);
void				ft_sha512_core(t_u64 w[80], t_u64 state[8]);
void				primestatecpy64(t_u64 state[8], t_u64 p_state[8]);
void				sha512_state_shuffle(t_u64 pstate[8], t_u64 mids[6]);
void				state_plus_pstate64(t_u64 state[8], t_u64 pstate[8]);

#endif
