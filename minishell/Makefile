# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeon <djeon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 19:30:48 by djeon             #+#    #+#              #
#    Updated: 2021/07/15 11:29:38 by djeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= gcc
#CC 				= gcc -g -fsanitize=address
# 컴파일 옵션 바꾸면 릭 테스트 해볼수 있습니다.
RM				= rm -rf
CFLAGS 			= -Wall -Wextra -Werror
NAME 			= minishell

#READLINE_LIB 	= -lreadline -L/Users/hoylee/.brew/opt/readline/lib
#READLINE_INC	= -I/Users/hoylee/.brew/opt/readline/include

READLINE_LIB 	= -lreadline -L/opt/homebrew/opt/readline/lib
READLINE_INC	= -I/opt/homebrew/opt/readline/include

LIBFT		= libft.a
LIBFT_DIR	= libft

SRC_DIR 	= srcs
SRC 		= srcs/minishell.c srcs/utils/utils.c srcs/parser/parse.c \
			  srcs/execute/exec.c srcs/utils/error_management.c \
			  srcs/execute/ft_cd.c srcs/execute/ft_exit.c \
			  srcs/execute/ft_env.c srcs/execute/ft_pwd.c \
			  srcs/execute/ft_export.c srcs/execute/export_utils.c \
			  srcs/signal_handle.c srcs/parser/alloc_token.c \
			  srcs/parser/cmd_split.c srcs/parser/get_parse_size.c \
			  srcs/redirection/redir_chk.c srcs/utils/ft_getenv.c \
			  srcs/redirection/redirect.c srcs/redirection/redirect_check.c \
			  srcs/execute/ft_echo.c srcs/execute/ft_unset.c \
			  srcs/execute/exec_utils.c srcs/utils/utils2.c \
			  srcs/parser/ft_alloc_word.c srcs/parser/d_quote_cnt.c \
			  srcs/parser/alloc_env_util.c srcs/parser/ft_split_cnt.c

OBJ_DIR 	= objs
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : 		$(NAME)

$(NAME) : 	$(LIBFT) $(OBJ)
			$(CC) $(CFLAGS) -o $@ $(OBJ) $(READLINE_LIB) $(READLINE_INC) \
			$(LIBFT)

$(LIBFT) :
			cd $(LIBFT_DIR); make
			cp $(LIBFT_DIR)/$(LIBFT) ./
			mkdir -p $(OBJ_DIR)/execute
			mkdir -p $(OBJ_DIR)/parser
			mkdir -p $(OBJ_DIR)/redirection
			mkdir -p $(OBJ_DIR)/utils

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -c $< -o $(<:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
			$(READLINE_INC)

clean :
			cd $(LIBFT_DIR); make clean
			$(RM) $(OBJ) $(OBJ_DIR)

fclean : 	clean
			cd $(LIBFT_DIR); make fclean
			$(RM) $(NAME) $(LIBFT)

re : 		fclean all

.PHONY :	all clean fclean
