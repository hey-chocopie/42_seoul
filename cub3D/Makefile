# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoylee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 17:51:13 by hoylee            #+#    #+#              #
#    Updated: 2020/11/26 19:37:23 by hoylee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MNAME = libmlx.dylib

LNAME = libft.a

NAME = cub3d.out

SRCS = hoylee_cub3d.c bmp.c	./gnl_for_cub3d/get_next_line.c ./gnl_for_cub3d/get_next_line_utils.c dot_cub_test.c ft_map.c ft_map_info.c ft_tool.c	ft_calc_fc.c ft_buf_malloc.c

MLX = a

LIBFT = b

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${MLX} ${LIBFT}
		${CC} ${CFLAGS}  -L .. -lmlx -L./libft -lft -L./printf -lftprintf -framework OpenGL -framework Appkit -o ${NAME} ${OBJS} libft.a libmlx.dylib\


$(MLX): 
		${MAKE} -C ./mlxfolder/
		cp ./mlxfolder/${MNAME}  ./ 
$(LIBFT):
		${MAKE} -C ./libft/


all:	${NAME}

clean:
		${RM} ${OBJS}
		cd ./mlxfolder/; make clean
		cd ./libft/; make fclean
		rm libmlx.dylib;
fclean:	clean
		${RM} ${NAME}

re:		fclean all


.PHONY : all clean fclean re
