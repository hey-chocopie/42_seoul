/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:48:46 by hoylee            #+#    #+#             */
/*   Updated: 2020/12/03 19:49:15 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_macos.h"

void	key_press_ad(int key, t_info *info)
{
	if (key == K_A)
	{
		if (info->key_d == 1)
		{
			info->key_save_ad = 'd';
			info->key_d = 0;
		}
		info->key_a = 1;
	}
	if (key == K_D)
	{
		if (info->key_a == 1)
		{
			info->key_save_ad = 'a';
			info->key_a = 0;
		}
		info->key_d = 1;
	}
}

int		key_press(int key, t_info *info)
{
	if (key == K_ESC)
	{
		ft_all_free(info);
		exit(0);
	}
	if (key == K_W)
	{
		if (info->key_s == 1)
		{
			info->key_save_ws = 's';
			info->key_s = 0;
		}
		info->key_w = 1;
	}
	if (key == K_S)
	{
		if (info->key_w == 1)
		{
			info->key_save_ws = 'w';
			info->key_w = 0;
		}
		info->key_s = 1;
	}
	key_press_ad(key, info);
	return (0);
}

void	key_release_ad(int key, t_info *info)
{
	if (key == K_A)
	{
		if (info->key_save_ad == 'd')
			ft_tool2_keysave_set(&(info->key_d), &(info->key_save_ad), 1, 0);
		else if (info->key_save_ad == 'a')
			ft_tool2_keysave_set(&(info->key_a), &(info->key_save_ad), 0, 0);
		info->key_a = 0;
	}
	if (key == K_D)
	{
		if (info->key_save_ad == 'a')
			ft_tool2_keysave_set(&(info->key_a), &(info->key_save_ad), 1, 0);
		else if (info->key_save_ad == 'd')
			ft_tool2_keysave_set(&(info->key_d), &(info->key_save_ad), 0, 0);
		info->key_d = 0;
	}
}

int		key_release(int key, t_info *info)
{
	if (key == K_ESC)
	{
		ft_all_free(info);
		exit(0);
	}
	if (key == K_W)
	{
		if (info->key_save_ws == 's')
			ft_tool2_keysave_set(&(info->key_s), &(info->key_save_ws), 1, 0);
		else if (info->key_save_ws == 'w')
			ft_tool2_keysave_set(&(info->key_w), &(info->key_save_ws), 0, 0);
		info->key_w = 0;
	}
	if (key == K_S)
	{
		if (info->key_save_ws == 'w')
			ft_tool2_keysave_set(&(info->key_w), &(info->key_save_ws), 1, 0);
		else if (info->key_save_ws == 's')
			ft_tool2_keysave_set(&(info->key_s), &(info->key_save_ws), 1, 0);
		info->key_s = 0;
	}
	key_release_ad(key, info);
	return (0);
}

void	ft_keypress(t_info *info)
{
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, &key_release, info);
}
