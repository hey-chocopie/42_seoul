/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:27:39 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/28 23:41:17 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACOS_H
# define KEY_MACOS_H



#include "./mlxfolder/mlx.h"
#include "./printf/ft_printf.h"
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

#define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64

//#define numSprites 19
typedef struct s_winsize
{
	int size_x;
	int size_y;
}				t_winsize;

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

typedef	struct	s_sprite
{
	double		x;
	double		y;
	int			texture;

}				t_sprite;

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				y;
	int				spr;
}				t_map;

typedef struct      s_pair
{
    double  first;
    int     second;
}                   t_pair;

typedef struct	s_cwall
{
	double raydir_xy[2];
	int     map_xy[2];
	double  sidedist_xy[2];
	double deltadist_xy[2];
	double perpwalldist;
	int		step_xy[2];
	int		hit;
	int		side;
	
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;

	double	wall_x;
	double	step;
	double	texpos;
	int		tex_y;
	int		tex_x;
}				t_cwall;


typedef struct	s_csp
{
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	transform_x;
	double	transform_y;
	int		screen_x;

	int		v_movescreen;
	int		sp_height;
	int		drawstart_y;
	int		drawend_y;
	int		drawstart_x;
	int		drawend_x;
	int		sprite_width;
	int		tex_x;	
}				t_cspr;


typedef struct	s_info
{
	t_map map;
	int err_m;
	int **fullmap;
	t_winsize	winsize;

	int map_width;
	int	map_height;
	int width;
	int height;
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
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

	int texture_x_size;
	int texture_y_size;
	int	texturecount;
	int	spriteflag;
	int dot_i;

	t_sprite *s_save;
	t_sprite *s_tmp;
	t_cwall cwall;
	t_cspr	spr;
}				t_info;

int save_bmp(t_info *info);
int     get_next_line(int fd, char **line);
int dot_cub_test(char **text, t_info *info);
int dot_mapset(char **text, t_info *info);
int ft_map(t_info *info, char *line, int *i);
int ft_errorprint(int a, t_info *info);

void    ft_input_texture_free(t_info *info);
int ft_map_info(t_info *info);
void ft_tool_mem_free(t_info *info);
int		ft_calc_fc(t_info *info);
int		ft_buf_texture_malloc(t_info *info);
void    ft_texture_input(t_info *info);
void    ft_calc_wall(t_info *info);
void    ft_calc_w_colr(t_info *info, int x);
int     ft_cal_sp(t_info *info);
int     ft_calc_sp_info(t_info *info, int *sp_order);
int		ft_main_loop(t_info *info);
void	ft_keypress(t_info *info);
int		ft_tool_errorprintf(int a, t_info *info);
int		ft_diretion(t_info *info, char **text, int jump, int adr);
int ft_floor_celing_texture(t_info *info, char **text, int jump, int adr);
int ft_r(t_info *info, char **text);
int     ft_slablen(t_info *info, char *line);
char    *ft_slab(t_info *info, char *line, int *i);
void	ft_setinfo(t_info *info);
void    ft_pos(t_info *info);
#endif
