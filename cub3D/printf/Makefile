# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frdescam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 16:00:31 by frdescam          #+#    #+#              #
#    Updated: 2020/12/03 12:33:15 by hoylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = aa.c libft.c ft_width_value.c ft_itoa_u.c ft_decimalnum.c ft_decimalnum2.c ft_octal.c ft_persent_count.c ft_discrimination.c ft_d.c ft_stprintf.c ft_stprintf2.c ft_string_stprintf.c ft_s_c.c ft_u_x_p_o.c


OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror 
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
