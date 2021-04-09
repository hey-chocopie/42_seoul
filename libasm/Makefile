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

NAME  = libasm.a
SRCS  = ft_strcmp.s ft_strlen.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS = ${SRCS:.s=.o}
NA		= nasm
RM		= rm -f
NFLAGS = -f macho64

.s.o:
		${NA} ${NFLAGS} -s $< -o ${<:.s=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY : all clean fclean re
