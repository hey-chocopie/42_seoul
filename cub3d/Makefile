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

MNAME = libmlx.dylib

LNAME = libft.a
NAME  = cub3D

SRCS  = hoylee_cub3d.c bmp.c	./gnl_for_cub3d/get_next_line.c ./gnl_for_cub3d/get_next_line_utils.c dot_cub_test.c ft_map.c ft_map_info.c ft_tool.c	ft_calc_fc.c ft_texture.c ft_calc_w_colr.c ft_calc_wall.c ft_cal_sp.c ft_calc_sp_info.c ft_main_loop.c ft_buf_texture_malloc.c ft_keypress.c ft_diretion.c ft_floor_celing_texture.c ft_r.c ft_slab.c ft_setinfo.c ft_pos.c ft_back_check.c ft_tool2.c

MLX = mlxfolder/libmlx.dylib
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
LIBFTPATH = libft
PRINTFPATH = printf
MLXPATH = mlxfolder
OBJS = ${SRCS:.c=.o}
FLAMEWORK = -framework OpenGL -framework Appkit
CC		= gcc
RM		= rm -f

CFLAGS =
#-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${MLX} ${LIBFT} ${PRINTF}
		${CC} ${CFLAGS} -L${MLXPATH} -lmlx -L${LIBFTPATH} -lft -L${PRINTFPATH} -lftprintf ${FLAMEWORK} -o ${NAME} ${OBJS}

$(MLX): 
		${MAKE} -C ./mlxfolder/
		cp ./mlxfolder/${MNAME}  ./ 
$(LIBFT):
		${MAKE} -C ./libft/

$(PRINTF):
		${MAKE} -C ./printf/


all:	${NAME}

clean:
		cd ./mlxfolder/; make clean
		cd ./libft/; make clean
		cd ./printf/; make clean
		${RM} ${OBJS}

fclean:	clean
		cd ./mlxfolder/; make fclean
		cd ./libft/; make fclean
		cd ./printf/; make fclean
		${RM} ${NAME} ${MNAME}

re:		fclean all

.PHONY : all clean fclean re
