// 2020.10.21해야할것. 
// 레이저가 벽을 만날떄 처리하기. 
// 최대한 벽까지 값 그리도록 만들어보기.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "cubd.h"
#include "../mlx/mlx.h"
#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define TILE_SIZE 32
# define ROWS 24
# define COLS 24
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define M_pi 3.14159265358979323846
# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))



int a;
int keyinput_x;
int keyinput_y;
double		angle_value;
//int test;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		map[ROWS][COLS];

	// 여기다가 선언한것들을 넣어주면 됨.
	t_posvalue		posvalue;
	t_dirvalue		dirvalue;
	t_planevalue	planevalue;
	t_rayvalue		rayvalue;
	t_mapvalue		mapvalue;
	t_ddaalgorism	ddaalgorism;
	double time;
	double oldtime;
	int angle;
	double angle_radian;
}				t_game;

double getradian(int angle)
{
	return angle * (M_pi / 180);
}

//Draw the line by DDA algorithm
void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;
	// x1 is (i * tile_size),  x2 is (i * tite_size),  i is cols count  , y1 is 0, and y2 is height
	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	//Absolute value 만약 세로의 값을 그리는 경우라면 deltaY가 크므로 step에 deltaY가 저장이 된다. 
	deltaX /= step;
	deltaY /= step;
	// 그릴값은 delta값에 1이나 혹은 -1 이 들어가게 된다.
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] =  0xb3b3b3;
		// 결국 입력되는 값은 여기의 입력값에 따라 상황이 바뀜.
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_line2(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	//Absolute value
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] =  0xFF0000;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		//horizontal
		//이친구의 입력값이 x일때 똑같은 이유는, y의 선만 그리기위해 만들어졌고, y의 값을 0에서 맥시멈 까지 그린다는 생각으로 값을 입력하였다 .중요한건 0부터 맥시멈 까지지 선을 그리는게 중요하다. 그래서 첫 시작값 y1은 0을 받았고, 두번쨰 값은 세로축의 맥시멈 값을 받았다. 
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		//--
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}



void	two_rays_lines(t_game *game)
{
		double inclination;
		int test;

		test = 0;
		inclination = (*game).rayvalue.raydirY / (*game).rayvalue.raydirX;

		// -- dda 알고리즘임. -------------------
		if (-1 <= inclination && inclination <= 1)
		{
			test = 0;
			if((*game).rayvalue.raydirX > 0)
 			{
				while(test < 400)
				{
					if((*game).rayvalue.raydirY > 0)
					{	
						game->img.data[((*game).posvalue.posY * TILE_SIZE  - (int)(floor(inclination * test))) * WIDTH + (*game).posvalue.posX * TILE_SIZE + test] = 	0x0FF000;
					}
					else if((*game).rayvalue.raydirY < 0)	
					{
						game->img.data[((*game).posvalue.posY * TILE_SIZE  - (int)(floor(inclination * test))) * WIDTH + (*game).posvalue.posX * TILE_SIZE + test] = 	0x0FF000;
					}
					test++;
				}
			}
			else if((*game).rayvalue.raydirX < 0)
			{
					while(test < 400)
				{
					if((*game).rayvalue.raydirY >= 0)
					{
						game->img.data[((*game).posvalue.posY * TILE_SIZE  + (int)(floor(inclination * test))) * WIDTH + (*game).posvalue.posX * TILE_SIZE - test] = 	0x0FF000;
					}
					else if((*game).rayvalue.raydirY < 0)	
					{
						game->img.data[((*game).posvalue.posY * TILE_SIZE  + (int)(floor(inclination * test))) * WIDTH + (*game).posvalue.posX * TILE_SIZE - test] = 	0x0FF000;
					}
					test++;
				}			
			}
		}
		else	
		{
			test = 0;
			if((*game).rayvalue.raydirY > 0)
			{
				while(test < 400)
				{
					if((*game).rayvalue.raydirX > 0)
					{	
						game->img.data[((*game).posvalue.posY * TILE_SIZE  - test) * WIDTH + (*game).posvalue.posX * TILE_SIZE + (int)floor(test / inclination)] = 	0x0FF000;
					}
					else if((*game).rayvalue.raydirX < 0)	
					{
						game->img.data[((*game).posvalue.posY * TILE_SIZE  - test) * WIDTH + (*game).posvalue.posX * TILE_SIZE + (int)floor(test / inclination)] = 	0x0FF000;
					}
					test++;
				}
			}
			else if((*game).rayvalue.raydirY < 0)
			{
					while(test < 400)
				{
					if((*game).rayvalue.raydirX > 0)
					{
						game->img.data[((*game).posvalue.posY * TILE_SIZE  + test) * WIDTH + (*game).posvalue.posX * TILE_SIZE - (int)floor(test / inclination)] = 	0x0FF000;
					}
					else if((*game).rayvalue.raydirX < 0)
					{
						game->img.data[((*game).posvalue.posY * TILE_SIZE  + test) * WIDTH + (*game).posvalue.posX * TILE_SIZE - (int)floor(test / inclination)] = 	0x0FF000;
					}
					test++;
				}			
			}
		}
}

void 	rays_lines(t_game *game)
{
	int x;
	double cameraX;
	x = 0;
	while(x < 50)
	{
		cameraX = 2 * x / (double) 50 - 1; 
		(*game).rayvalue.raydirX = (*game).dirvalue.dirX + (*game).planevalue.planeX * cameraX;
		(*game).rayvalue.raydirY = (*game).dirvalue.dirY + (*game).planevalue.planeY * cameraX;


		//---맵에서 광선 쏘아보기. ---
//		printf("raydirX == %f\n", (*game).rayvalue.raydirX);
//		printf("raydirY == %f\n\n", (*game).rayvalue.raydirY);
		
		two_rays_lines(game);

		//---------광선-------------
		x++;
		(*game).mapvalue.mapX = (*game).posvalue.posX;
		(*game).mapvalue.mapY = (*game).posvalue.posY;
		(*game).ddaalgorism.deltadistX = fabs(1 / (*game).rayvalue.raydirX); // 이거 하는데 덜대값이 계산이 안되는거 같음 해결방법을 알아보자. 
		(*game).ddaalgorism.deltadistY = fabs(1 / (*game).rayvalue.raydirY);

		if ((*game).rayvalue.raydirX < 0)
		{
			(*game).ddaalgorism.stepX = -1;
			(*game).ddaalgorism.sidedistX = ((*game).posvalue.posX - (*game).mapvalue.mapX) * (*game).ddaalgorism.deltadistX;
		} // 크기에 따라서 어디로 붙는지를 정리한다.
		else
		{
			(*game).ddaalgorism.stepX = 1;
			(*game).ddaalgorism.sidedistX = ((*game).mapvalue.mapX + 1.0 - (*game).posvalue.posX) * (*game).ddaalgorism.deltadistX;
		}
		if ((*game).rayvalue.raydirY < 0)
		{
			(*game).ddaalgorism.stepY = -1;
			(*game).ddaalgorism.sidedistY = ((*game).posvalue.posY - (*game).mapvalue.mapY) * (*game).ddaalgorism.deltadistY;
		}
		else
		{
			(*game).ddaalgorism.stepY = 1;
			(*game).ddaalgorism.sidedistY = ((*game).mapvalue.mapY + 1.0 - (*game).posvalue.posY) * (*game).ddaalgorism.deltadistY;
		}
		//여기까지는 값들이 sidedist값과 deltadist값 길이를 정리하기위한 함수들이다. 이제 필요한건, 정리된 함수들을 가지고 sideX또는 sideY의 길이를 보고 어느길이가 더 ㄱ가까운지를 분석하여 ㅇ가까운 곳ㄷ의 함수가 만약 빈칸이 아니라면 hit = 1을 채우기 위한 함수가 필요하다. 

		while ((*game).ddaalgorism.hit == 0)
		{
			if ((*game).ddaalgorism.sidedistX < (*game).ddaalgorism.sidedistY) //sidedist 는 단순히 길이의 크기이므로 가까운거 먼저 검사해야함.
			{
				(*game).ddaalgorism.sidedistX += (*game).ddaalgorism.sidedistY;
				(*game).mapvalue.mapX += (*game).ddaalgorism.stepX;
				//-----------------여기서 부터 하면됨. -----
				(*game).ddaalgorism.side = 0;
			}
			else
			{
				(*game).ddaalgorism.sidedistY += (*game).ddaalgorism.sidedistY;
				(*game).mapvalue.mapY += (*game).ddaalgorism.stepY;
				(*game).ddaalgorism.side = 1;
			}
			if ((*game).map[(*game).mapvalue.mapX][(*game).mapvalue.mapY] > 0)
			(*game).ddaalgorism.hit = 1;
			printf("test: %f\n", (*game).ddaalgorism.sidedistX);
		}
		
	}
}

void	draw_rectangle1(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y  + i) * WIDTH + x + j] = 	0xFFF000;
			j++;
		}
		i++;
	}
}

void	draw_rectangle0(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y  + i) * WIDTH + x + j] = 	0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_rectangle2(t_game *game, int x, int y)
{
	int i;
	int j;
	if(keyinput_x >= TILE_SIZE)
	{
		keyinput_x = 0;
		(*game).posvalue.posY++;
		x++;
	}
	else if(keyinput_x < 0)
	{
		keyinput_x = 31;
		(*game).posvalue.posY--;
		x--;
	}
	if(keyinput_y >= TILE_SIZE)
	{
		keyinput_y = 0;

		(*game).posvalue.posX++;
		y++;
	}
	else if(keyinput_y < 0)
	{
		keyinput_y = 31;
		(*game).posvalue.posX--;
		y--;
	}
	y *= TILE_SIZE;
	x *= TILE_SIZE;
	i = keyinput_x;
	j = keyinput_y;
	while ((0 <= keyinput_x && i < keyinput_x + 5) && keyinput_x + 5 < TILE_SIZE+5)
	{
		j = keyinput_y;
		while ((0 <= keyinput_y && j < keyinput_y + 5) && keyinput_y + 5 < TILE_SIZE + 5)
		{
			//game->img.data[(x  + i) * WIDTH + y + j] = 	0x888888;
			game->img.data[(x  + i) * WIDTH + y + j] = 	0xff0000;
			j++;
		}
		i++;
	}
}



void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle1(game, j, i);
 			else if (game->map[i][j] == 0)
				draw_rectangle0(game, j, i);
//			if(i == (*game).posvalue.posX && j == (*game).posvalue.posY)
//				draw_rectangle2(game, j, i);	
			j++;
		}
		i++;
	}
}

int		deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int 	close(t_game *game)
{
		exit(0);
}

void	radian_change(t_game *game)
{
		//(*game).angle
		(*game).dirvalue.dirX = (*game).dirvalue.dirX * cos((*game).angle_radian) -  (*game).dirvalue.dirY * sin((*game).angle_radian);
		(*game).dirvalue.dirY = (*game).dirvalue.dirX * sin((*game).angle_radian) + (*game).dirvalue.dirY * cos((*game).angle_radian);
		(*game).planevalue.planeX = (*game).planevalue.planeX * cos((*game).angle_radian) -  (*game).planevalue.planeY * sin((*game).angle_radian);
		(*game).planevalue.planeY = (*game).planevalue.planeX * sin((*game).angle_radian) +  (*game).planevalue.planeY * cos((*game).angle_radian);
}

int				key_press(int keycode, t_game *game)
{

	if (keycode == KEY_W)//Action when W key pressed
		keyinput_x--;
	else if (keycode == KEY_S) //Action when S key pressed
		keyinput_x++;
	else if (keycode == KEY_A) //Action when S key pressed
	{
		(*game).angle++;
		printf("%d", (*game).angle);

		(*game).angle_radian = getradian(2);
		radian_change(game);
//		keyinput_y--;
	}
	else if (keycode == KEY_D) //Action when S key pressed
	{
		(*game).angle--;

		(*game).angle_radian = getradian(-2);
		radian_change(game);
//		keyinput_y++;
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
//	printf("x: %d\n", (*game).posvalue.posX);
//	printf("y: %d\n", (*game).posvalue.posX);
	return (0);
}

void	game_init(t_game *game)
{	
//	int map[ROWS][COLS] = {
//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
//	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
//	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//	};
	int map[ROWS][COLS]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);

// ------------ㅂ빨간 주인공 ------ 
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if(i == (*game).posvalue.posX && j == (*game).posvalue.posY)
				draw_rectangle2(game, j, i);	
			j++;
		}
		i++;
	}
// ----------------
	rays_lines(game);
	
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	
	return (0);
}

int		main(void)
{
	t_game			game;

//	test = 0;
	game.posvalue.posX = 12;
	game.posvalue.posY = 12;
	game.dirvalue.dirX = -1;
	game.dirvalue.dirY = 0;
	game.planevalue.planeX = 0;
	game.planevalue.planeY = 0.66;
	game.time = 0;
	game.oldtime = 0;

	game.angle = 0;
	game.angle_radian = getradian(game.angle);

	keyinput_x = 0;
	keyinput_y = 0;
	angle_value = 90;
	a = 0;
	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
