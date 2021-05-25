# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoylee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 17:51:13 by hoylee            #+#    #+#              #
#    Updated: 2020/12/03 18:57:19 by hoylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = libft.a

NAME  = push_swap

SRCS  = push_swap.c

LIBFT = libft/libft.a

LIBFTPATH = libft

OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f

CFLAGS =-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} -L${LIBFTPATH} -lft -o ${NAME} ${OBJS}

$(LIBFT):
		${MAKE} -C ./libft/

all:	${NAME}

clean:
		cd ./libft/; make clean
		${RM} ${OBJS}

fclean:	clean
		cd ./libft/; make fclean
		${RM} ${NAME}
re:		fclean all

.PHONY : all clean fclean re
