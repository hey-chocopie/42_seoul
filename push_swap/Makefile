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

SRCS  = push_swap.c argc_check_and_make_lis.c frequently_used_functions.c function_push.c function_reverse_rotate.c function_rotate.c function_swap.c  range_five.c two_three_optimization.c rr_rrr_location.c data_save_load.c pivot_select.c pivot_split_stack.c

LIBFT = libft/libft.a

LIBFTPATH = libft

OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f

CFLAGS =
#-Wall -Wextra -Werror

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
