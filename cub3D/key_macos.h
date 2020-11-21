/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohlee <yohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:40:13 by oouklich          #+#    #+#             */
/*   Updated: 2020/11/21 12:26:29 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACOS_H
# define KEY_MACOS_H


#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
** Keyboard LETTERS
*/

# define K_A 0
# define K_B 11
# define K_C 8
# define K_D 2
# define K_E 14
# define K_F 3
# define K_G 5
# define K_H 4
# define K_I 34
# define K_J 38
# define K_K 40
# define K_L 37
# define K_M 46
# define K_N 45
# define K_O 31
# define K_P 35
# define K_Q 12
# define K_R 15
# define K_S 1
# define K_T 17
# define K_U 32
# define K_V 9
# define K_W 13
# define K_X 7
# define K_Y 16
# define K_Z 6

/*
** Keyboard ARROWS
*/

# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125

/*
** Keyboard NUMPAD
*/

# define K_NP_DIV 75
# define K_NP_MUL 67
# define K_NP_MIN 78
# define K_NP_PLU 69
# define K_NP_1	83
# define K_NP_2	84
# define K_NP_3	85
# define K_NP_4	86
# define K_NP_5	87
# define K_NP_6	88
# define K_NP_7	89
# define K_NP_8	91
# define K_NP_9	92

/*
** Keyboard MISC
*/

# define K_SP 49
# define K_ESC 53
# define K_TAB 48

/*
** Mouse
*/
# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

#define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

#define numSprites 19


typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

struct	Sprite
{
	double		x;
	double		y;
	int			texture;

};

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				y;
	int				spr;
}				t_map;


typedef struct	s_info
{
	t_map map;
	int err_m;
	int **worldmap2;


	int width;
	int height;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_esc;
	t_img	img;
	int		**buf;
	double	*zBuffer;
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	int mx;
	int my;
	int		f_texture;
	int		c_texture;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *s_texture;
	char *ft_texture;
	char *ct_texture;
	//bmp----
	int bmpflag;
	int	bmpwidth;
	int bmpheigth;
	// test
	int		**skybox;
}				t_info;

int save_bmp(t_info *info);
int     get_next_line(int fd, char **line);
int dot_cub_test(char **text, t_info *info);
int dot_mapset(char **text, t_info *info);
int ft_map(t_info *info, char *line, int *i);
#endif