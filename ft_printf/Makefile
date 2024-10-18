# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseniak <nseniak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 14:53:02 by nseniak           #+#    #+#              #
#    Updated: 2022/06/01 14:57:57 by nseniak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= ft_printf.c ft_putnbr_absolute.c get_precision.c print_c.c\
 print_p.c print_u.c print_x.c ft_strchrn.c	nbr_len.c print_d_i.c print_s.c\
 print_upperx.c to_hexa.c zero.c
OBJS		= ${SRCS:.c=.o}
LIBFT		= libft/libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a 

%.o: %.c ${SRCS}
		$(CC) $(FLAGS) -c -o $@ $< 

$(NAME): ${OBJS}
		make -C libft
		mv $(LIBFT) ./$(NAME)
		ar rcs $(NAME) $(OBJS)


all: $(NAME)


clean:
		make -C libft clean
		rm -f ${OBJS}

bonus:	all

fclean:	clean
		make -C libft fclean
		rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
