# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoylee <hoylee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 23:08:17 by hoylee            #+#    #+#              #
#    Updated: 2021/08/04 23:16:32 by hoylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
RM			= rm -rf
CFLAGS 		= -Wall -Wextra -Werror
NAME 		= philo
MKOBJS		= test
SRC_DIR 	= srcs

SRC 		= srcs/philosophers.c srcs/utils.c srcs/t_philo_thread.c srcs/time_utils.c \
				srcs/argv_check.c srcs/malloc_mutex_and_pthread.c srcs/monitor_thread.c \
				srcs/pthread.utils.c srcs/ft_libft.c

OBJ_DIR 	= objs
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : 		$(NAME)

$(NAME) : 	$(MKOBJS) $(OBJ)
			$(CC) $(CFLAGS) -o $@ $(OBJ)

$(MKOBJS) :
			mkdir -p $(OBJ_DIR)
					  
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -c $< -o $(<:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

clean :
			$(RM) $(OBJ) $(OBJ_DIR)

fclean : 	clean
			$(RM) $(NAME)

re : 		fclean all

.PHONY :	all clean fclean
