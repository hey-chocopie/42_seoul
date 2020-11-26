/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoylee_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/26 19:29:16 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlxfolder/mlx.h"
#include "key_macos.h"
#include "./printf/ft_printf.h"


//struct Sprite	sprite[info->map.spr] =
//{
//	{20.5, 11.5, 10}, //green light in front of playerstart
	//green lights in every room
//	{18.5,4.5, 10},
//	{10.0,4.5, 10},
//	{10.0,12.5,10},
//	{3.5, 6.5, 10},
//	{3.5, 20.5,10},
//	{3.5, 14.5,10},
//	{14.5,20.5,10},

	//row of pillars in front of wall: fisheye test
//	{18.5, 10.5, 1},
//	{18.5, 11.5, 4},
//	{18.5, 12.5, 1},

	//some barrels around the map
//	{21.5, 1.5, 8},
//	{15.5, 1.5, 8},
//	{16.0, 1.8, 8},
//	{16.2, 1.2, 8},
//	{3.5,  2.5, 8},
//	{9.5, 15.5, 8},
//	{10.0, 15.1,8},
//	{10.5, 15.8,8},
//};

int spriteflag = 0;


typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

void	key_update(t_info *info);

//static int	compare(const void *first, const void *second)
//{
//	if (*(int *)first > *(int *)second)
//		return (1);
//	else if (*(int *)first < *(int *)second)
//		return (-1);
//	else
//		return (0);
//}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < amount)
	{
		j=0;
		while(j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

int		sortSprites(t_info *info,int *order, double *dist, int amount)
{
	int i;

	i = 0;
	t_pair	*sprites;
	if(!(sprites = (t_pair*)malloc(sizeof(t_pair) * amount)))
	{
		info->err_m = -12;
		return(-1);
	}
	while(i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while(i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
	return(0);
}

//int	info->fullmap[mapWidth][mapHeight] =
//									{
//										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
//										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
//										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
//										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
//										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
//										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
//										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
//										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
//										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
//										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
//										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
//										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
//										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
//										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
//										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
//										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
//										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
//										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
//										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
//										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
//										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
//										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
//										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
//										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
//									};

void	draw(t_info *info)
{
	for (int y = 0; y < info->height; y++)
	{
		for (int x = 0; x < info->width; x++)
		{
			info->img.data[(info->img).size_l / (info->img.bpp / 8)	*y  + x] = info->buf[y][x];		
		}
	}
	if(info->bmpflag == 0)
		save_bmp(info);
	info->bmpflag =1;
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_string_put(info->mlx, info->win, 20, (*info).height - 20, 16711680, "hoylee_cub3d");

}

//----------------------

void	ft_calc_w_set(t_info *info, int x)
{
	info->cwall.raydir_xy[0] = info->dirX + info->planeX * (2 * x / (double)info->width - 1);
	info->cwall.raydir_xy[1] = info->dirY + info->planeY * (2 * x / (double)info->width - 1);
	info->cwall.map_xy[0] = (int)info->posX;
	info->cwall.map_xy[1] = (int)info->posY;
	info->cwall.deltadist_xy[0] = fabs(1 / info->cwall.raydir_xy[0]);
	info->cwall.deltadist_xy[1] = fabs(1 / info->cwall.raydir_xy[1]);
	info->cwall.hit = 0;
}

void	ft_calc_w_step_set_info(t_info *info)
{
		if(info->cwall.raydir_xy[0] < 0)
		{
			info->cwall.step_xy[0] = -1;
			info->cwall.sidedist_xy[0] = (info->posX - info->cwall.map_xy[0]) * info->cwall.deltadist_xy[0];
		}
		else
		{
			info->cwall.step_xy[0] = 1;
			info->cwall.sidedist_xy[0] = (info->cwall.map_xy[0] + 1.0 - info->posX) * info->cwall.deltadist_xy[0];
		}
		if(info->cwall.raydir_xy[1] < 0)
		{
			info->cwall.step_xy[1] = -1;
			info->cwall.sidedist_xy[1] = (info->posY - info->cwall.map_xy[1]) * info->cwall.deltadist_xy[1];
		}
		else
		{
			info->cwall.step_xy[1] = 1;
			info->cwall.sidedist_xy[1] = (info->cwall.map_xy[1] + 1.0 - info->posY) * info->cwall.deltadist_xy[1];
		}

}

void	ft_calc_w_ps_map(t_info *info)
{
		while (info->cwall.hit == 0)
		{
			if(info->cwall.sidedist_xy[0] < info->cwall.sidedist_xy[1])
			{
			info->cwall.sidedist_xy[0] += info->cwall.deltadist_xy[0];
			info->cwall.map_xy[0] += info->cwall.step_xy[0];
			info->cwall.side = 0;
			}
			else
			{
			info->cwall.sidedist_xy[1] += info->cwall.deltadist_xy[1];
			info->cwall.map_xy[1] += info->cwall.step_xy[1];
			info->cwall.side = 1;
			}
			if(info->fullmap[info->cwall.map_xy[0]][info->cwall.map_xy[1]] > 0) info->cwall.hit = 1;
		}
		if(info->cwall.side == 0) info->cwall.perpwalldist = (info->cwall.map_xy[0] - info->posX + (1 - info->cwall.step_xy[0]) / 2) / info->cwall.raydir_xy[0];
		else          info->cwall.perpwalldist = (info->cwall.map_xy[1] - info->posY + (1 - info->cwall.step_xy[1]) / 2) / info->cwall.raydir_xy[1];
}


void	ft_calc_w_set_psline(t_info *info)
{
		info->cwall.lineheight = (int)(info->height / info->cwall.perpwalldist);
		info->cwall.drawstart = -info->cwall.lineheight / 2 + info->height / 2;
		if(info->cwall.drawstart < 0) info->cwall.drawstart = 0;
		info->cwall.drawend = info->cwall.lineheight / 2 + info->height / 2;
		if(info->cwall.drawend >= info->height) info->cwall.drawend = info->height - 1;
		info->cwall.texnum = info->fullmap[info->cwall.map_xy[0]][info->cwall.map_xy[1]] - 1;
		if(info->cwall.map_xy[0] == 0)
			info->cwall.texnum =0;
		if(info->cwall.map_xy[0] == info->map.y - 1)
			info->cwall.texnum =1;
		if(info->cwall.map_xy[1] == 0)
			info->cwall.texnum =4;
		if(info->cwall.map_xy[1] == info->map.x - 1)
			info->cwall.texnum =3;

}
void	ft_calc_w_set_pstexture(t_info *info)
{
		if (info->cwall.side == 0) info->cwall.wall_x = info->posY + info->cwall.perpwalldist * info->cwall.raydir_xy[1];
		else           info->cwall.wall_x = info->posX + info->cwall.perpwalldist * info->cwall.raydir_xy[0];
		info->cwall.wall_x -= floor(info->cwall.wall_x);
		info->cwall.tex_x = (int)(info->cwall.wall_x * (double)info->texture_x_size);
		if(info->cwall.side == 0 && info->cwall.raydir_xy[0] > 0) info->cwall.tex_x = info->texture_x_size - info->cwall.tex_x - 1;
		if(info->cwall.side == 1 && info->cwall.raydir_xy[1] < 0) info->cwall.tex_x = info->texture_x_size - info->cwall.tex_x - 1;
		info->cwall.step = 1.0 * info->texture_y_size / info->cwall.lineheight;
		info->cwall.texpos = (info->cwall.drawstart - info->height / 2 + info->cwall.lineheight / 2) * info->cwall.step;

}

void	ft_calc_w_put_colr(t_info *info, int x)
{
	int j;

	j = info->cwall.drawstart;
	while(j < info->cwall.drawend)
	{
		info->cwall.tex_y = (int) info->cwall.texpos & (info->texture_y_size - 1);
		info->cwall.texpos += info->cwall.step;
		int color = info->texture[info->cwall.texnum][info->texture_y_size * info->cwall.tex_y + info->cwall.tex_x];
		if(info->cwall.side == 1) color = (color / 2) & 8355711;
		info->buf[j][x] = color;
		j++;
	}
}

void	ft_calc_wall(t_info *info)
{
	int x;

	x = 0;
	while(x < info->width)
	{
		ft_calc_w_set(info, x);
		ft_calc_w_step_set_info(info);
		ft_calc_w_ps_map(info);
		ft_calc_w_set_psline(info);
		ft_calc_w_set_pstexture(info);
		ft_calc_w_put_colr(info, x);
		info->zBuffer[x] = info->cwall.perpwalldist;
		x++;
	}
}
int		ft_calc_sp_info(t_info *info, int *sp_order)
{
	int i;
	double	sp_distance[info->map.spr];

	i = 0;
	while(i < info->map.spr)
	{
		sp_order[i] = i;
		sp_distance[i] = ((info->posX - info->s_save[i].x) * (info->posX - info->s_save[i].x) + (info->posY - info->s_save[i].y) * (info->posY - info->s_save[i].y));
		i++;
	}
	if(-1 == sortSprites(info, sp_order, sp_distance, info->map.spr))
		return (-1);
	return(0);
}

void	ft_calc_sp_set(t_info *info, int *sp_order, int i)
{
	info->spr.sprite_x = info->s_save[sp_order[i]].x - info->posX;
	info->spr.sprite_y = info->s_save[sp_order[i]].y - info->posY;
	info->spr.invdet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY);
	info->spr.transform_x = info->spr.invdet * (info->dirY * info->spr.sprite_x - info->dirX * info->spr.sprite_y);
	info->spr.transform_y = info->spr.invdet * (-info->planeY * info->spr.sprite_x + info->planeX * info->spr.sprite_y);
	info->spr.screen_x = (int)((info->width / 2) * (1 + info->spr.transform_x / info->spr.transform_y));

}

void	ft_calc_sp_ps_draw(t_info *info, int *sp_order, int i)
{
		int vMove = 0.0;
		if(spriteflag < 7000000 && info->s_save[sp_order[i]].texture== 2 && (info->s_texture == 0))
			vMove = 0;
		else if(spriteflag >= 7000000 && spriteflag <= 10000000&& info->s_save[sp_order[i]].texture== 2 && (info->s_texture == 0))
			vMove = 150;
		info->spr.v_movescreen = (int)(vMove / info->spr.transform_y);
		info->spr.sp_height = (int)fabs((info->height / info->spr.transform_y) / 1);
		info->spr.drawstart_y = -info->spr.sp_height / 2 + info->height / 2 + info->spr.v_movescreen;
		if(info->spr.drawstart_y < 0) info->spr.drawstart_y = 0;
		info->spr.drawend_y = info->spr.sp_height / 2 + info->height / 2 + info->spr.v_movescreen;
		if(info->spr.drawend_y >= info->height) info->spr.drawend_y = info->height - 1;

		info->spr.sprite_width = (int)fabs((info->height / info->spr.transform_y) / 1);
		info->spr.drawstart_x = -info->spr.sprite_width / 2 + info->spr.screen_x;
		if(info->spr.drawstart_x < 0) info->spr.drawstart_x = 0;
		info->spr.drawend_x = info->spr.sprite_width / 2 + info->spr.screen_x;
		if(info->spr.drawend_x >= info->width) info->spr.drawend_x = info->width - 1;


}

int		ft_calc_sp_input(t_info *info, int i, int *sp_order, int y)
{
	int d;
	int tex_y;
	int color;

	d = (y-info->spr.v_movescreen) * 256 - info->height * 128 + info->spr.sp_height * 128;
	tex_y = ((d * info->texture_y_size) / info->spr.sp_height) / 256;
	color = info->texture[info->s_save[sp_order[i]].texture][info->texture_x_size * tex_y + info->spr.tex_x];
	if(spriteflag < 7000000 && info->s_save[sp_order[i]].texture == 2)
	{
		color = info->texture[info->s_save[sp_order[i]].texture][info->texture_x_size * tex_y + info->spr.tex_x];
		spriteflag++;
	}
	else if(info->s_save[sp_order[i]].texture == 2)
	{
		color = info->texture[7][info->texture_x_size * tex_y + info->spr.tex_x];
		spriteflag++;
		if(spriteflag >10000000)
			spriteflag = 0;
	}	
	return(color);		
}

void	ft_calc_sp_draw(t_info *info, int *sp_order, int i)
{
	int stripe;
	int color;
	stripe = info->spr.drawstart_x;
		while(stripe < info->spr.drawend_x)
		{
			info->spr.tex_x = (int)((256 * (stripe - (-info->spr.sprite_width / 2 + info->spr.screen_x)) * info->texture_x_size / info->spr.sprite_width) / 256);
			if(info->spr.transform_y > 0 && stripe > 0 && stripe < info->width && info->spr.transform_y < info->zBuffer[stripe])
			for(int y = info->spr.drawstart_y; y < info->spr.drawend_y; y++)
			{
				color = ft_calc_sp_input(info, i, sp_order, y);
				if((color & 0x00FFFFFF) != 0) info->buf[y][stripe] = color;
			}
			stripe++;
		}
}

int		ft_cal_sp(t_info *info)
{
	int		sp_order[info->map.spr];
	int		i;

	i = 0;
	ft_calc_sp_info(info, sp_order);
	for(int i = 0; i < info->map.spr; i++)
	{
		ft_calc_sp_set(info, sp_order, i);
		ft_calc_sp_ps_draw(info, sp_order, i);
		ft_calc_sp_draw(info, sp_order, i);

	}
	return(0);
}

void	calc(t_info *info)
{
	ft_calc_fc(info);
	ft_calc_wall(info);
	ft_cal_sp(info);

}
int	mouseexit()
{
	exit(0);
	return (0);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

void	key_update(t_info *info)
{
	if (info->key_w)
	{
		if (!info->fullmap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!info->fullmap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (info->key_s)
	{
		if (!info->fullmap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!info->fullmap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (info->key_d)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (info->key_a)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (info->key_esc)
		exit(0);
}

int		key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 1;
	else if (key == K_A)
		info->key_a = 1;
	else if (key == K_S)
		info->key_s = 1;
	else if (key == K_D)
		info->key_d = 1;
	return (0);
}

int		key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 0;
	else if (key == K_A)
		info->key_a = 0;
	else if (key == K_S)
		info->key_s = 0;
	else if (key == K_D)
		info->key_d = 0;
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	// 여기 사이즈 바꾸면됨
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
//(info->img).size_l / (info->img.bpp / 8)	*y  + x
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}



void	load_hoyleetexture(t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < info->texture_x_size)
	{
		while(j < info->texture_y_size)
		{
			(*info).texture[0][info->texture_x_size * j + i] = 65536 * 0 + 254 * 248 + 223;
			(*info).texture[1][info->texture_x_size * j + i] = 65536 * 254 + 254 * 236 + 2;
			(*info).texture[2][info->texture_x_size * j + i] = 65536 * 239 + 254 * 194 + 233;
			(*info).texture[3][info->texture_x_size * j + i] = 65536 * 172 + 254 * 161 + 232;
			(*info).texture[5][info->texture_x_size * j + i] = 65536 * 1 + 254 * 42 + 45;
			(*info).texture[6][info->texture_x_size * j + i] = 65536 * 110 + 254 * 58 + 108;
			if(info->f_texture != -1)
				(*info).texture[5][info->texture_x_size * j + i] = info->f_texture;
			if(info->c_texture != -1)
				(*info).texture[6][info->texture_x_size * j + i] = info->c_texture;
			j++;
		}
		j = 0;
		i++;
	}
}

void	map_texture(t_info *info)
{
	t_img	img;


	load_image(info, info->texture[2], "textures/barrel.xpm", &img);
	load_image(info, info->texture[7], "textures/sprite8smallgom.xpm", &img);
	if(info -> no_texture != 0)
		load_image(info, info->texture[0], info -> no_texture, &img);
	if(info -> so_texture != 0)
		load_image(info, info->texture[1], info -> so_texture, &img);
	if(info -> we_texture != 0)
		load_image(info, info->texture[4], info -> we_texture, &img);
	if(info -> ea_texture != 0)
		load_image(info, info->texture[3], info -> ea_texture, &img);
	if(info -> s_texture != 0)
		load_image(info, info->texture[2], info -> s_texture, &img);
	if(info -> ft_texture != 0)
		load_image(info, info->texture[5], info -> ft_texture, &img);
	if(info -> ct_texture != 0)
		load_image(info, info->texture[6], info -> ct_texture, &img);
	if(info -> s_texture != 0)
		load_image(info, info->texture[7], info -> s_texture, &img);

}

void	load_texture(t_info *info)
{
	t_img	img;

//	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
//	load_image(info, info->texture[1], "textures/sprite8smallgom.xpm", &img);
//	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
//	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
//	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
//	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
//	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
	load_image(info, info->texture[8], "textures/barrel.xpm", &img);
	load_image(info, info->texture[9], "textures/pillar.xpm", &img);
	load_image(info, info->texture[10], "textures/greenlight.xpm", &img);

	load_image(info, info->texture[12], "textures/test5sky.xpm", &img);

	load_image(info, info->texture[13], "textures/test2white.xpm", &img);

	load_image(info, info->texture[9], "textures/sprite7biggom.xpm", &img);
	load_image(info, info->texture[14], "textures/test4whitewall.xpm", &img);

	if(info -> so_texture != 0)
		load_image(info, info->texture[1], info -> so_texture, &img);
}

void	ft_pos(t_info *info)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < info->map.y)
	{
		while (++j < info->map.x)
		{
			c = info->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				info->posY = (double)j + 0.5;
				info->posX = (double)i + 0.5;
				info->dirY = (c == 'E' || c == 'W') ? 1 : 0;
				info->dirY *= (c == 'W') ? -1 : 1;
				info->dirX = (c == 'S' || c == 'N') ? 1 : 0;
				info->dirX *= (c == 'N') ? -1 : 1;
			}
		}
		j = -1;
	}
	info->planeX = info->dirY * (0.66);
	info->planeY = info->dirX * (-0.66);
}


	int ft_errorprint(int a, t_info *info)
	{
		info->err_m = -a;
		return (-1);
	}
void ft_setinfo(t_info *info)
{
	info->map.x = 0;
	info->map.y = 0;

	info->map.spr = 0;
	info->map.tab = NULL;
	info->no_texture = 0;
	info->so_texture = 0;
	info->we_texture = 0;
	info->ea_texture = 0;
	info->s_texture = 0;
	info->ft_texture = 0;
	info->ct_texture = 0;

	info->f_texture = -1;
	info->c_texture = -1;

	info->bmpflag = 0;
	info->posX = 22.0;
	info->posY = 11.5;
	info->dirX = 1.0;
	info->dirY = 0.0;
	info->planeX = 0.66;
	info->planeY = 0.0;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;

	info->err_m = 0;
	info->texturecount = 8;
	info->texture = 0;
	info->zBuffer = 0;

	info->width = 600;
	info->height = 600;

	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;

	info->texture_x_size = 64;
	info->texture_y_size = 64;
	info-> s_save = 0;
	info-> s_tmp = 0;
//info->texture_x_size
}

int ft_mapparse(t_info *info)
{
	int fd;
	char *text;
	int check;
	char *aa;
	int i;
	int errno;
	errno = 0;
	i = 0;
	check = 1;
    fd=open("./map/2.cub",O_RDONLY);
	while(check != 0 && check != -1 )
	{
		check = get_next_line(fd, &text);
		while(text[i] == ' ')
			i++;
		text = i + text;	
		aa = text;
		if(0 > (errno = dot_cub_test(&text, info)))
		{
			printf("dural;");
			ft_input_texture_free(info);
			if(info->err_m != 0)
				ft_printf("%d : %s", info->err_m*(-1), strerror(info->err_m));
			ft_printf("%d : %s" , errno*(-1),  strerror(errno));
			return (-1);
		}
		free(aa);
	}
	close(fd);

	return(0);
}



int ft_texture_malloc(t_info *info)
{
	if (!(info->texture = (int **)malloc(sizeof(int *) * info->texturecount)))
	{
		ft_tool_mem_free(info);
		return (-1);
	}
	for (int i = 0; i < info->texturecount ; i++)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (info->texture_y_size * info->texture_x_size))))
		{
			ft_tool_mem_free(info);
			return (-1);
		}
	}
	for (int i = 0; i < info->texturecount ; i++)
	{
		for (int j = 0; j < info->texture_y_size * info->texture_x_size; j++)
		{
			info->texture[i][j] = 0;
		}
	}
	return(0);
}

void ft_display_set(t_info *info)
{
	info->win = mlx_new_window(info->mlx,  info->width, info->height,"mlx");
	info->img.img = mlx_new_image(info->mlx,  info->width ,info->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);

//	mlx_clear_window(info->mlx, info->win);
}

int	main(void)
{
	t_info info;
	ft_setinfo(&info);

	info.mlx = mlx_init();
	mlx_get_screen_size(info.mlx, &info.winsize.size_x, &info.winsize.size_y);
	if(-1 == ft_mapparse(&info))
		return(-1);
	ft_pos(&info);
	if(-1 == ft_map_info(&info))
		return (-1);
	if(-1 == ft_buf_malloc(&info))
		return (-1);
	if(-1 == ft_texture_malloc(&info))
		return(-1);
	load_hoyleetexture(&info);
	map_texture(&info);
	ft_display_set(&info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_loop(info.mlx);
	printf("1");
}
