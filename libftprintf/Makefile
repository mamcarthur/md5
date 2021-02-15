# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcarthu <mmcarthu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 20:15:35 by mmcarthu          #+#    #+#              #
#    Updated: 2019/05/23 23:58:03 by mmcarthu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = srcs/*.c \
	  libft/*.c \

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@ar rc $(NAME) *.o
	@mkdir exes
	@mv *.o exes

clean:
	@/bin/rm -f *.o
	@rm -rf exes
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all
