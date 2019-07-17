# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 22:33:23 by mmcarthu          #+#    #+#              #
#    Updated: 2019/05/24 00:25:12 by mmcarthu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRCS =	ft_ssl_srcs/*.c \
		md5_srcs/*.c \
		sha224_srcs/*.c \
		sha256_srcs/*.c \
		sha384_srcs/*.c \
		sha512_srcs/*.c \
		ssl_md5_srcs/*.c

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME):
	@make -C libftprintf re
	gcc -Wall -Wextra -Werror $(SRCS) -o $(NAME) $(LIB)

clean:
	@make clean -C libftprintf

fclean:
	@make fclean -C libftprintf
	@rm -f $(NAME)

re: fclean all
