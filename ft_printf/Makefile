# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 02:42:42 by chanjeon          #+#    #+#              #
#    Updated: 2022/04/16 07:49:55 by chanjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_utils.c ft_print_idux.c ft_print_csp.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
			ar rcs $@ $^

clean :
			rm -f $(OBJS)

fclean : clean
			rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
