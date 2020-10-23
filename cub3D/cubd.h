/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:14:56 by hoylee            #+#    #+#             */
/*   Updated: 2020/10/22 14:05:57 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBD_H
# define CUBD_H
typedef struct          s_posvalue{
	int		posX;
	int		posY;
	}t_posvalue;

typedef struct          s_dirvalue{
	double	dirX;
	double	dirY;
	}t_dirvalue;

typedef struct          s_planevalue{
	double	planeX;
	double	planeY;
	}t_planevalue;

typedef struct          s_rayvalue{
	double	raydirX;
	double	raydirY;
	}t_rayvalue;

typedef struct			s_mapvalue{
	int		mapX;
	int		mapY;
	}t_mapvalue;

typedef struct			s_ddaalgorism{
	double	sidedistX;	//첫 시작위치부터 x정수축에 닿을떄까지 길ㄱ이
	double	sidedistY;
	double	deltadistX;	//x 축 한칸이 증가할떄 증가하는 대각선 ㅇ길이
	double	deltadistY;
	double	perpwalldist;	//나중에 광선의 이동거리를 계산하는데 사용

	int stepX;	//건너띄는 방향에 따라 stepX또는 stepY에 +1 or -1형태로 저장되게 됩니다. 
	int stepY;
	int hit; //벽과 부딪혔는지 확
	int side;
	}t_ddaalgorism;

#endif	
