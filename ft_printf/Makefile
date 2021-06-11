# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frdescam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 16:00:31 by frdescam          #+#    #+#              #
#    Updated: 2021/06/11 17:27:42 by hoylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_printf.c srcs/libft.c srcs/ft_width_value.c srcs/ft_itoa_u.c srcs/ft_decimalnum.c srcs/ft_decimalnum2.c srcs/ft_octal.c srcs/ft_persent_count.c srcs/ft_discrimination.c srcs/ft_d.c srcs/ft_stprintf.c srcs/ft_stprintf2.c srcs/ft_string_stprintf.c srcs/ft_s_c.c srcs/ft_u_x_p_o.c


OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all


.PHONY : all clean fclean re
