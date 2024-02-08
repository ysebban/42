# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysebban <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:59:35 by ysebban           #+#    #+#              #
#    Updated: 2022/12/19 14:38:35 by ysebban          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c my_putnbr_base.c colors.c

LIB = ./libft/libtf.a

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

CC = gcc 

FLAGS = -c -Wall -Wextra -Werror

NAME = libftprintf.a

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME) 

clean :
	$(MAKE) clean -C ./libft 
	rm -rf $(OBJS)

fclean : clean 
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
