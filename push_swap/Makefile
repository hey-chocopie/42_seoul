# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoylee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 17:51:13 by hoylee            #+#    #+#              #
#    Updated: 2021/06/05 21:53:56 by hoylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = libft.a

NAME  = push_swap
NAME_2 = checker

SRCS  = push_swap.c argc_check_and_make_lis.c frequently_used_functions.c function_push.c function_reverse_rotate.c function_rotate.c function_swap.c  range_five.c two_three_optimization.c rr_rrr_location.c data_save_load.c pivot_select.c pivot_split_stack_b.c pivot_split_stack_a.c ascending_input.c

SRCS_2 = f_checker/checker.c f_checker/function_push_checker.c f_checker/function_reverse_rotate_checker.c f_checker/function_rotate_checker.c f_checker/function_swap_checker.c argc_check_and_make_lis.c frequently_used_functions.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

LIBFT = libft/libft.a

LIBFTPATH = libft

OBJS = ${SRCS:.c=.o}
OBJS_2 = ${SRCS_2:.c=.o}

CC		= gcc
RM		= rm -f


CFLAGS =-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} -L${LIBFTPATH} -lft -o ${NAME} ${OBJS}

$(NAME_2) : $(OBJS_2) ${LIBFT}
		${CC} ${CFLAGS} -L${LIBFTPATH} -lft -o ${NAME_2} ${OBJS_2}


$(LIBFT):
		${MAKE} -C ./libft/

all:	${NAME} ${NAME_2}

clean:
		cd ./libft/; make clean
		${RM} ${OBJS}
		${RM} ${OBJS_2}

fclean:	clean
		cd ./libft/; make fclean
		${RM} ${NAME}
		${RM} ${NAME_2}

re:		fclean all

.PHONY : all clean fclean re
