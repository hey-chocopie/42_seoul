/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hoylee_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:30:20 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/19 15:29:28 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlxfolder/mlx.h"
#include "key_macos.h"

struct Sprite	sprite[numSprites] =
{
	{20.5, 11.5, 10}, //green light in front of playerstart
	//green lights in every room
	{18.5,4.5, 10},
	{10.0,4.5, 10},
	{10.0,12.5,10},
	{3.5, 6.5, 10},
	{3.5, 20.5,10},
	{3.5, 14.5,10},
	{14.5,20.5,10},

	//row of pillars in front of wall: fisheye test
//	{18.5, 10.5, 1},
	{18.5, 11.5, 4},
//	{18.5, 12.5, 1},

	//some barrels around the map
	{21.5, 1.5, 8},
	{15.5, 1.5, 8},
	{16.0, 1.8, 8},
	{16.2, 1.2, 8},
	{3.5,  2.5, 8},
	{9.5, 15.5, 8},
	{10.0, 15.1,8},
	{10.5, 15.8,8},
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

int	worldMap[mapWidth][mapHeight] =
									{
										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
									};

void	draw(t_info *info)
{
	for (int y = 0; y < info->height; y++)
	{
		for (int x = 0; x < info->width; x++)
		{
		//	printf("y = %d, x = %d\n", y, x);
			info->img.data[(info->img).size_l / (info->img.bpp / 8)	*y  + x] = info->buf[y][x];		
			//* info->width
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_string_put(info->mlx, info->win, 20, (*info).height - 20, 16711680, "hoylee_cub3d");
	if(info->bmpflag == 0)
		save_bmp(info);
	info->bmpflag = 1;
}


//484840000
void	calc(t_info *info)
{
	//FLOOR CASTING
	for(int y = info->height / 2 + 1; y < info->height; ++y)
	{
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = info->dirX - info->planeX;
		float rayDirY0 = info->dirY - info->planeY;
		float rayDirX1 = info->dirX + info->planeX;
		float rayDirY1 = info->dirY + info->planeY;
		// Current y position compared to the center of the screen (the horizon)
		int p = y - info->height / 2;
		// Vertical position of the camera.
		float posZ = 0.5 * info->height;
		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;
		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / info->width;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / info->width;
		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = info->posX + rowDistance * rayDirX0;
		float floorY = info->posY + rowDistance * rayDirY0;
		for(int x = 0; x < info->width; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);
			// get the texture coordinate from the fractional part
			int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
			int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			int color;
			color = info->texture[5][texWidth * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker
			info->buf[y][x] = color;
			//ceiling (symmetrical, at height - y - 1 instead of y)
			color = info->texture[6][texWidth * ty + tx];
			color = (color >> 1) & 8355711; // make a bit darker
			info->buf[info->height - y - 1][x] = color;
		}
	}
	// WALL CASTING
	for(int x = 0; x < info->width; x++)
	{
		//calculate ray position and direction
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
		//calculate step and initial sideDist
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
			if(worldMap[mapX][mapY] > 0) hit = 1;
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
		int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = info->posY + perpWallDist * rayDirY;
		else           wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		//x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
		if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - info->height / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			// hoyleetest
			if (texNum < 4)
				texNum = 0;
			// 이거 바꿔서 코드 짜야함. 
			int color = info->texture[texNum][texHeight * texY + texX];
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
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < info->width && transformY < info->zBuffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - info->height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * texHeight) / spriteHeight) / 256;
				int color;
				color = info->texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX];
				if(spriteflag < 5000000 && sprite[spriteOrder[i]].texture == 4)
				{
				color = info->texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
					spriteflag++;
				}
				else if(sprite[spriteOrder[i]].texture == 4)
				{
				color = info->texture[9][texWidth * texY + texX];
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
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (info->key_s)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
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
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}



void	load_hoyleetexture(t_info *info)
{

	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
//			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
//			int ycolor = y * 256 / texHeight;
//			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			(*info).texture[11][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
//			info.texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
//			info.texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
//			info.texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
//			info.texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
//			info.texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
//			info.texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
//			info.texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}

}

void	map_texture(t_info *info)
{
	t_img	img;

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

}

void	load_texture(t_info *info)
{
	t_img	img;

//	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
	//textures/eagle.xpm"
//	load_image(info, info->texture[1], "textures/sprite8smallgom.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
	load_image(info, info->texture[8], "textures/barrel.xpm", &img);
	load_image(info, info->texture[9], "textures/pillar.xpm", &img);
	load_image(info, info->texture[10], "textures/greenlight.xpm", &img);

	load_image(info, info->texture[12], "textures/test5sky.xpm", &img);

	load_image(info, info->texture[13], "textures/test2white.xpm", &img);

	load_image(info, info->texture[9], "textures/sprite7biggom.xpm", &img);
	load_image(info, info->texture[14], "textures/test4whitewall.xpm", &img);
	
	load_image(info, info->skybox[0], "textures/22.xpm", &img);


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

void	ft_input_texture_free(t_info *info)
{
	if(info->no_texture != 0)
		free(info -> no_texture);
	else if(info->so_texture != 0)
		free(info -> so_texture);
	else if(info->we_texture != 0)
		free(info -> we_texture);
	else if(info->ea_texture != 0)
		free(info -> ea_texture);
	else if(info->s_texture != 0)
		free(info -> s_texture);
	else if(info->ft_texture != 0)
		free(info -> ft_texture);
	else if(info->ct_texture != 0)
		free(info -> ct_texture);
}


int	main(void)
{

	t_info info;
	info.mlx = mlx_init();
	int sizexx;
	int	sizeyy;

	info.no_texture = 0;
	info.so_texture = 0;
	info.we_texture = 0;
	info.ea_texture = 0;
	info.s_texture = 0;
	info.ft_texture = 0;
	info.ct_texture = 0;


	info.f_texture = -1;
	info.c_texture = -1;

	info.bmpflag = 0;
	info.posX = 22.0;
	info.posY = 11.5;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;
	info.key_a = 0;
	info.key_w = 0;
	info.key_s = 0;
	info.key_d = 0;
	info.key_esc = 0;

	int texturecount = 15;
	int x = 0;


	mlx_get_screen_size(info.mlx, &sizexx, &sizeyy);
	info.width = 600;
	info.height = 600;
// ======
		int fd;
		char *text;
		int check;
		char *aa;
		int i;
		aa= (char *)malloc(sizeof(char)*1);
		i = 0;
		check = 1;
        fd=open("./map/2.cub",O_RDONLY);
		while(check != 0 && check != -1 )
		{
			check = get_next_line(fd, &text);
//			while(text[i] == ' ')
//				i++;
//			text = i + text;
			if(-1 == dot_cub_test(&text, &info))
			{
				printf("oh no\n");
				ft_input_texture_free(&info);		
				return (-1);
			}
			free(text);
		}
		close(fd);
//====
	printf("NO, %s\n", info.no_texture);
	printf("SO, %s\n", info.so_texture);
	printf("WE, %s\n", info.we_texture);
	printf("EA, %s\n", info.ea_texture);
	printf("S, %sfinish\n", info.s_texture);
	printf("FT, %s\n", info.ft_texture);
	printf("CT, %s\n", info.ct_texture);
	printf("F, %d\n", info.f_texture);
	printf("C, %d\n", info.c_texture);

//	free(info.S_texture);
//	if (info.no_texture != 0)
//		free(info.no_texture);
	if(sizexx <info.width)
	{
		info.width =  sizexx;	
	}
	if(sizeyy <info.height)
	{
		info.height = sizeyy;
	}
	info.bmpwidth = info.width;
	info.bmpheigth = info.height;

	if (!(info.buf = (int **)malloc(sizeof(int *) * info.height)))
		return (-1);
	while(x < info.height)
		if (!(info.buf[x++] = (int *)malloc(sizeof(int) * (info.width))))
			return (-1);
	if (!(info.zBuffer = (double *)malloc(sizeof(double) * (info.width))))
		return (-1);
	for (int i = 0; i < info.height; i++)
	{
		for (int j = 0; j < info.width; j++)
		{
			info.buf[i][j] = 0;
		}
	}
	//  -----a

	if (!(info.skybox = (int **)malloc(sizeof(int *) * 1)))
		return (-1);
	if (!(info.skybox[0] = (int *)malloc(sizeof(int) * (642 * 360))))
		return (-1);
	for (int i = 0; i <  1; i++)
	{
		for (int j = 0; j < 642*360; j++)
		{
			info.skybox[i][j] = 0;
		}
	}

	// -----


	if (!(info.texture = (int **)malloc(sizeof(int *) * texturecount)))
		return (-1);

	for (int i = 0; i < texturecount ; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < texturecount ; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info.texture[i][j] = 0;
		}
	}
	load_hoyleetexture(&info);
	load_texture(&info);
//	map_texture(&info);
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	

	info.win = mlx_new_window(info.mlx,  info.width, info.height,"mlx");
	info.img.img = mlx_new_image(info.mlx,  info.width ,info.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);


//	mlx_mouse_move(info.mlx, &x, &y);


	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
//	printf("11111%s\n" , info.no_texture);
	mlx_loop(info.mlx);
}
