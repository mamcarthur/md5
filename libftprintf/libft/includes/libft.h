/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:48:56 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/05/13 11:15:07 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/syslimits.h>

# define BUFF_SIZE 200
# define IS_SPACE(A) A == ' ' || A == '\n' || A == '\t'
# define MORE_SPACES(A) A == '\f' || A == '\r' || A == '\v'

/*
** COLORS
*/

# define COLOR_BLACK "\033[22;30m"
# define COLOR_RED "\033[22;31m"
# define COLOR_GREEN "\033[22;32m"
# define COLOR_BROWN "\033[22;33m"
# define COLOR_BLUE "\033[22;34m"
# define COLOR_MAGENTA "\033[22;35m"
# define COLOR_CYAN "\033[22;36m"
# define COLOR_GRAY "\033[22;37m"
# define COLOR_DARKGRAY "\033[01;30m"
# define COLOR_LIGHTRED "\033[01;31m"
# define COLOR_LIGHTGREEN "\033[01;32m"
# define COLOR_YELLOW "\033[01;33m"
# define COLOR_LIGHTBLUE "\033[01;34m"
# define COLOR_LIGHTMAGENTA "\033[01;35m"
# define COLOR_LIGHTCYAN "\033[01;36m"
# define COLOR_WHITE "\033[01;37m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** CHARACTER CHECKS
*/

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_iswhitespace(int c);

/*
** CONVERSIONS
*/

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(char *s);
char				*ft_itoa(int n);

/*
** OUTPUT
*/

void				ft_putchar(char c);
void				ft_putendl(char *str);
void				ft_putstr(char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);

/*
** MEM
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** LST
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlink);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** STR
*/

char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(char *haystack, char *needle, size_t len);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, char *s2);
char				*ft_strncat(char *s1, char *s2, size_t n);
char				*ft_strchr(char *s, int c);
char				*ft_strrchr(char *s, int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_ccountwords(char const *s, char c);
int					ft_countspacedwords(char const *s);
char				*ft_strctrim(char const *s, char c);
size_t				ft_strclen(const char *s, char c);

/*
** Swap
*/

void				ft_charswap(char *a, char *b);
void				ft_intswap(int *a, int *b);

/*
** MINE
*/

int					get_next_line(const int fd, char **line);
void				ft_free2darray(char ***array, size_t len);
int					*ft_insertionsort(int *arr, size_t arraysize);
long				ft_absval(int k);
int					max(int a, int b);

#endif
