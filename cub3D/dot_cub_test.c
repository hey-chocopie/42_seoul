/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_cub_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:11:44 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/18 18:58:29 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlxfolder/mlx.h"
#include "key_macos.h"
#include "./libft/libft.h"
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned	char	*ss2;
	unsigned	char	*ss1;

	ss1 = (unsigned	char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while ((ss1[i] == ss2[i] && (i < n)) && (s1[i] != 0 || s2[i] != 0))
		i++;
	if (i == n)
		return (0);
	return (ss1[i] - ss2[i]);
}

int ft_R(t_info *info, char **text)
{
	int i;
	int j;
	int flag;
	flag = 0;
	char textsave[100];
	i = 1;
	ft_memset(textsave, 0, 100);
	while((*text)[i] != '\n')
	{
		j = 0;
		while((*text)[i] >= '0' && (*text)[i] <= '9')
		{
			textsave[j] = (*text)[i];	
			j++;
			i++;
		}
		if(textsave[0] != 0)
		{
			if (flag == 0)
				info -> width = ft_atoi(textsave);
			else if (flag == 1)
				info -> height = ft_atoi(textsave);
			ft_memset(textsave, 0, 100);
			flag++;
		}
		if ((*text)[i] == ' ')
			i++;
		if (((*text)[i] != ' ' && (*text)[i] < '0' && (*text)[i] < '9' && (*text)[i] == 0) || flag == 2)
			return (-1);
	}
	return (0);
}

void texture_value(t_info *info, int adr, char *textsave)
{
	if(adr == 0)
		info -> NO_texture = textsave;
	else if(adr == 1)
		info -> SO_texture = textsave;
	else if(adr == 2)
		info -> WE_texture = textsave;
	else if(adr == 3)
		info -> EA_texture = textsave;
	else if(adr == 4)
		info -> x_texture = textsave;
	else if(adr == 5)
		info -> CT_texture = textsave;
	else if(adr == 6)
		info -> FT_texture = textsave;
}

int ft_floor_celing_texture(t_info *info, char **text, int jump, int adr)
{
	int flag;
	char value[4];
	int i;
	int save;

	adr = 1;
	flag = 0;
	while((*text)[jump])
	{
		i = 0;
		while((*text)[jump + i] >= '0' && (*text)[jump + i] <= '9')
		{
			if (i > 3)
				return (-1);
			value[i] = (*text)[jump + i];
			i++;
		}
		value[i] = 0;
		if (i == 0)
			jump++;
		else if (i != 0)
		{
			jump = jump + i;
			flag ++;
		}
		if (flag == 1 && value[0] != 0)
			save = ft_atoi(value);			
		if (flag > 1 && flag <= 3 && value[0] != 0)
			save = ft_atoi(value) * save;			
		if (flag > 3)
			return (-1);
	}
	if(adr == 7)
		info -> F_texture = save;
	if(adr == 8)
		info -> C_texture = save;
	return (0);
}



int ft_diretion(t_info *info, char **text, int jump, int adr)
{
	int i;
	int j;
	char *textsave;
	int textlen;

	textlen = (int)strlen(*text);
	
	i = jump;
	j = 0;
	if(!(textsave = (char *)(malloc(sizeof(char) * (textlen - jump + 1)))))
		return (-1);
	if(textlen < jump)
		return (-1);
	ft_memset(textsave, 0,(textlen - jump + 1));
	while((*text)[i] == ' ')
		i++;
	while((*text)[i + j] != '\n' && (*text)[i + j] != 0 && (*text)[i + j] != ' ')
	{
		textsave[j] = (*text)[i + j];
		j++;
	}
	textsave[j] = 0;
	texture_value(info, adr, textsave);
	if(info -> bmpwidth == adr)
		printf("1");
	if((*text)[i+j] != 0)
		return (-1);
	return (0);
}
int	dot_cub_test(char **text, t_info *info)
{

	if(!ft_strncmp(*text, "R ", 2))
		ft_R(info, text);
	else if(!ft_strncmp(*text, "NO ", 3))
	{
		if(-1 == ft_diretion(info, text, 3, 0))
			return (-1);
	}
	else if(!ft_strncmp(*text, "SO ", 3))
	{
		if(-1 == ft_diretion(info, text, 3, 1))
			return (-1);
	}
	else if(!ft_strncmp(*text, "WE ", 3))
	{
		if(-1 == ft_diretion(info, text, 3, 2))
			return (-1);
	}
	else if(!ft_strncmp(*text, "EA ", 3))
	{
		if(-1 == ft_diretion(info, text, 3, 3))
			return (-1);
	}
	else if(!ft_strncmp(*text, "S ", 2))
	{
		if(-1 == ft_diretion(info, text, 2, 4))
			return (-1);
	}
	else if(!ft_strncmp(*text, "CT ", 3))
	{
		if(-1 == ft_diretion(info, text, 2, 5))
			return (-1);
	}
	else if(!ft_strncmp(*text, "FT ", 3))
	{
		if(-1 == ft_diretion(info, text, 2, 6))
			return (-1);
	}
	else if(!ft_strncmp(*text, "F ", 2))
	{
		if(-1 == ft_floor_celing_texture(info, text, 2, 7))
			return (-1);
	}
	else if(!ft_strncmp(*text, "C ", 2))
	{
		if(-1 == ft_floor_celing_texture(info, text, 2, 8))
			return (-1);
	}
//	if(info->bmpwidth == 1)
//		printf("11");
//	if((*text)[0] != '\n')
//	{
//		printf("Error");
//		return (-1);
//	}
	return (0);
}
//. R = 해상도 
//   NO = 북쪽 텍스쳐
//   SO = 남쪽 텍스쳐
//   WE = 왼쪽 텍스쳐
//   EA = 동쪽 텍스쳐
//   S  = 스프라이트 텍스쳐
//   F = 바닥 텍스쳐
//   c = 천장 텍스쳐
