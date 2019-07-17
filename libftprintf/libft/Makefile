# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 13:25:19 by mmcarthu          #+#    #+#              #
#    Updated: 2019/05/23 23:58:57 by mmcarthu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
		ft_isalnum.c \
  		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putstr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_atoi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strclr.c \
		ft_memmove.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_strctrim.c \
		ft_ccountwords.c \
		ft_countspacedwords.c \
		ft_charswap.c \
		ft_intswap.c \
		ft_strclen.c \
		ft_lstdelone.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_iswhitespace.c \
		get_next_line.c \
		ft_free2darray.c \
		ft_absval.c \
		ft_max.c \

all: $(NAME)


$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@echo "gcc -c -Wall -Werror -Wextra *.c"
	@ar rc libft.a *.o

clean:
	@/bin/rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
