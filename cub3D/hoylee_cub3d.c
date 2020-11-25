/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoylee_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/25 14:10:50 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlxfolder/mlx.h"
#include "key_macos.h"
#include "./printf/ft_printf.h"

struct Sprite	sprite[numSprites] =
{
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
	{18.5, 11.5, 4},
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
};

int		spriteOrder[numSprites];
double	spriteDistance[numSprites];
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

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
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
		}
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	//std::vector<std::pair<double, int>> sprites(amount);
	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	//std::sort(sprites.begin(), sprites.end());
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
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


void	calc(t_info *info)
{
	ft_calc_fc(info);
	for(int x = 0; x < info->width; x++)
	{
		double cameraX = 2 * x / (double)info->width - 1; //x-coordinate in camera space
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
			}
			else
			{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
			}
			//Check if ray has hit a wall
			if(info->fullmap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
		if(side == 0) perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else          perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		//Calculate height of line to draw on screen
		int lineHeight = (int)(info->height / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + info->height / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + info->height / 2;
		if(drawEnd >= info->height) drawEnd = info->height - 1;
		//texturing calculations
		int texNum = info->fullmap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = info->posY + perpWallDist * rayDirY;
		else           wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		//x coordinate on the texture
		int texX = (int)(wallX * (double)info->texture_x_size);
		if(side == 0 && rayDirX > 0) texX = info->texture_x_size - texX - 1;
		if(side == 1 && rayDirY < 0) texX = info->texture_x_size - texX - 1;
		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * info->texture_y_size / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - info->height / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (info->texture_y_size - 1) in case of overflow
			int texY = (int)texPos & (info->texture_y_size - 1);
			texPos += step;
			// hoyleetest
			if (texNum < 4)
				texNum = 0;
			// 이거 바꿔서 코드 짜야함. 
			int color = info->texture[texNum][info->texture_y_size * texY + texX];
			if(side == 1) color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}

		//SET THE ZBUFFER FOR THE SPRITE CASTING
		info->zBuffer[x] = perpWallDist; //perpendicular distance is used
	}

	//SPRITE CASTING
	//sort sprites from far to close
	for(int i = 0; i < numSprites; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((info->posX - sprite[i].x) * (info->posX - sprite[i].x) + (info->posY - sprite[i].y) * (info->posY - sprite[i].y)); //sqrt not taken, unneeded
	}
	sortSprites(spriteOrder, spriteDistance, numSprites);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < numSprites; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = sprite[spriteOrder[i]].x - info->posX;
		double spriteY = sprite[spriteOrder[i]].y - info->posY;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY); //required for correct matrix multiplication

		double transformX = invDet * (info->dirY * spriteX - info->dirX * spriteY);
		double transformY = invDet * (-info->planeY * spriteX + info->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

		int spriteScreenX = (int)((info->width / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites
		#define uDiv 1
		#define vDiv 1
		int vMove = 0.0;
		if(spriteflag < 5000000 && sprite[spriteOrder[i]].texture== 4)
			vMove = 150;
		else if(spriteflag >= 5000000 && spriteflag <= 10000000&& sprite[spriteOrder[i]].texture== 4)
			vMove = 50;
		int vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen
		int spriteHeight = (int)fabs((info->height / transformY) / vDiv); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + info->height / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + info->height / 2 + vMoveScreen;
		if(drawEndY >= info->height) drawEndY = info->height - 1;

		//calculate width of the sprite
		int spriteWidth = (int)fabs((info->height / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= info->width) drawEndX = info->width - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * info->texture_x_size / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < info->width && transformY < info->zBuffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - info->height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * info->texture_y_size) / spriteHeight) / 256;
				int color;
				color = info->texture[sprite[spriteOrder[i]].texture][info->texture_x_size * texY + texX];
				if(spriteflag < 5000000 && sprite[spriteOrder[i]].texture == 4)
				{
				color = info->texture[sprite[spriteOrder[i]].texture][info->texture_x_size * texY + texX]; //get current color from the texture
					spriteflag++;
				}
				else if(sprite[spriteOrder[i]].texture == 4)
				{
				color = info->texture[7][info->texture_x_size * texY + texX];
					spriteflag++;
					if(spriteflag >10000000)
						spriteflag = 0;
				}			
				if((color & 0x00FFFFFF) != 0) info->buf[y][stripe] = color;
			}
		}
	}
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
	mlx_hook((*info).win, 17, 1L << 17, mouseexit, info);
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
			if(info->f_texture != 0)
				(*info).texture[5][info->texture_x_size * j + i] = info->f_texture;
			if(info->c_texture != 0)
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

	load_image(info, info->texture[4], "textures/sprite8smallgom.xpm", &img);
	load_image(info, info->texture[7], "textures/sprite7biggom.xpm", &img);
	if(info -> no_texture != 0)
		load_image(info, info->texture[0], info -> no_texture, &img);
	if(info -> so_texture != 0)
		load_image(info, info->texture[1], info -> so_texture, &img);
	if(info -> we_texture != 0)
		load_image(info, info->texture[2], info -> we_texture, &img);
	if(info -> ea_texture != 0)
		load_image(info, info->texture[3], info -> ea_texture, &img);
	if(info -> s_texture != 0)
		load_image(info, info->texture[4], info -> s_texture, &img);
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


//	printf("dlrpanjswl?==%sfin\n", info -> so_texture);


//	if(info -> no_texture != 0)
//		load_image(info, info->texture[0], info -> no_texture, &img);
	if(info -> so_texture != 0)
		load_image(info, info->texture[1], info -> so_texture, &img);
//	if(info -> we_texture != 0)
//		load_image(info, info->texture[2], info -> no_texture, &img);
//	if(info -> ea_texture != 0)
//		load_image(info, info->texture[3], info -> no_texture, &img);
//	if(info -> s_texture != 0)
//		load_image(info, info->texture[4], info -> no_texture, &img);
//	if(info -> ft_texture != 0)
//		load_image(info, info->texture[5], info -> no_texture, &img);
//	if(info -> ct_texture != 0)
//		load_image(info, info->texture[6], info -> no_texture, &img);


}

//void	ft_input_texture_free(t_info *info)
//{
//	if(info->no_texture != 0)
//	{
//		free(info -> no_texture);
//		info->no_texture = 0;
//	}
//	else if(info->so_texture != 0)
//	{
//		free(info -> so_texture);
//		info->so_texture = 0;
//	}
//	else if(info->we_texture != 0)
//	{
//		free(info -> we_texture);
//		info->we_texture = 0;
//	}
//	else if(info->ea_texture != 0)
//	{
//		free(info -> ea_texture);
//		info->ea_texture = 0;
//	}
//	else if(info->s_texture != 0)
//	{
//		free(info -> s_texture);
//		info->s_texture = 0;
//	}
//	else if(info->ft_texture != 0)
//	{
//		free(info -> ft_texture);
//		info->ft_texture = 0;
//	}
//	else if(info->ct_texture != 0)
//	{
//		free(info -> ct_texture);
//		info->ct_texture = 0;
//	}
//}

//int		ft_mapcheck(t_info *info)
//{
//	int		i;
//	int		j;
//
//	i = 0;
//	j = 0;
//
//	while (i < info->map.y)
//	{
//		j = 0;
//		while (j < info->map.x)
//		{
//			if (info->map.tab[i][j] != '1' && i == 0)
//				return (-1);
//			else if (info->map.tab[i][j] != '1' && i == info->map.y - 1)
//				return (-1);
//			else if (info->map.tab[i][j] != '1' && j == 0)
//				return (-1);
//			else if (info->map.tab[i][j] != '1' && j == info->map.x - 1)
//				return (-1);
//			j++;
//		}
//		i++;
//	}
//	return (0);
//}

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
				info->posY = (double)i + 0.5;
				info->posX = (double)j + 0.5;
				info->dirX = (c == 'E' || c == 'W') ? 1 : 0;
				info->dirX *= (c == 'W') ? -1 : 1;
				info->dirY = (c == 'S' || c == 'N') ? 1 : 0;
				info->dirY *= (c == 'N') ? -1 : 1;
				
				info->posY = 5 + 0.5;
				info->posX = 2 + 0.5;
				//rintf("pos x %f, pos Y,%f " ,info->posX, info->posY);

				//info->err.p++;
			}
		}
		j = -1;
	}
	info->planeX = info->dirY * (0.66);
	info->planeY = info->dirX * (-0.66);


}

//int ft_mapcp(t_info *info)
//{
//	int		**mapsave;
//	int		i;
//	int		j;
//
//	if(!(mapsave = (int **)malloc(sizeof(int *) * (info->map.y))))
//		return(-12);
//	i = 0;
//	while(i < info->map.y)
//	{
//		if(!(mapsave[i] = (int *)malloc(sizeof(int) * (info->map.x))))
//		{
//			free(mapsave);
//			return(-12);
//		}
//		i++;
//	}
//	i = 0;
//	while(i < info->map.y)
//	{
//		j = 0;
//		while(j < info->map.x)
//		{
//			if(info->map.tab[i][j] > '2')
//				mapsave[i][j] = 0;
//			else
//				mapsave[i][j] = info->map.tab[i][j] - 48;
//			j++;
//		}
//		i++;
//	}
//	info->fullmap = mapsave;
//	i = -1;
//	j = 0;
//	while(i++ < info-> map.y)
//	{
//		free(info->map.tab[i]);
//		info->map.tab[i] = 0;
//	}
//	free(info->map.tab);
//	info->map.tab = 0;
//	return(0);
//}

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

int ft_buf_malloc(t_info *info)
{
	int i = 0;
	if (!(info->buf = (int **)malloc(sizeof(int *) * info->height)))
	{
		ft_input_texture_free(info);
		ft_printf("%d : %s", 12, strerror(-12));		
		return (-1);
	}
	while(i < info->height)
	{
		if (!(info->buf[i] = (int *)malloc(sizeof(int) * (info->width))))
		{
			ft_input_texture_free(info);
			free(info->buf);
			info->buf = 0;
			ft_printf("%d : %s", 12, strerror(-12));		
			return (-1);
		}
		i++;
	}
	if (!(info->zBuffer = (double *)malloc(sizeof(double) * (info->width))))
	{	
		ft_tool_mem_free(info);
		return (-1);
	}
	i = 0;
	int j = 0;
	while(i < info->height)
	{
		j = 0;
		while(j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
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
