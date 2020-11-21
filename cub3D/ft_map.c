/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:40:54 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/20 19:44:55 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "key_macos.h"
#include "./libft/libft.h"

//int		ft_xpm(t_info *info, unsigned int **adr, char *file)
//{
//	int		fd;
//	void	*img;
//	int		tab[5];
//
//	if (ft_namecheck(file, "xpm") == 0)
//		return (-1);
//	if ((fd = open(file, O_RDONLY)) == -1)
//		return (-1);
//	close(fd);
//	img = mlx_xpm_file_to_image(info->mlx.ptr, file, &tab[0], &tab[1]);
//	if (img == NULL || tab[0] != 64 || tab[1] != 64)
//		return (-1);
//	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
//	free(img);
//	return (0);
//}
//
//int		ft_texture(t_info *info, unsigned int **adr, char *line, int *i)
//{
//	char	*file;
//	int		j;
//
//	if (*adr != NULL)
//		return (-7);
//	(*i) += 2;
//	ft_spaceskip(line, i);
//	j = *i;
//	while (line[*i] != ' ' && line[*i] != '\0')
//		(*i)++;
//	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
//		return (-8);
//	*i = j;
//	j = 0;
//	while (line[*i] != ' ' && line[*i] != '\0')
//		file[j++] = line[(*i)++];
//	file[j] = '\0';
//	j = ft_xpm(s, adr, file);
//	free(file);
//	return (j == -1 ? -9 : 0);
//}

int		ft_slablen(t_info *info, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			count++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			count++;
		else if (line[i] == 'E')
			count++;
		i++;
	}
	if (info->map.x != 0 && info->map.x != count)
		return (-1);
	return (count);
}

char	*ft_slab(t_info *info, char *line, int *i)
{
	char	*slab;
	int		j;

	if (!(slab = malloc(sizeof(char) * (ft_slablen(info, line) + 1))))
		return (NULL);
	j = 0;
	while (line[*i] != '\0')
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			slab[j++] = line[*i];
		else if (line[*i] == '2')
		{
			slab[j++] = line[*i];
			info->map.spr++;
		}
		else if (line[*i] != ' ')
		{
			free(slab);
			return (NULL);
		}
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

int		ft_map(t_info *info, char *line, int *i)
{
	char	**tmp;
	int		j;

	info->err_m = 1;
	if (!(tmp = malloc(sizeof(char *) * (info->map.y + 2))))
		return (-11);
	j = -1;
	while (++j < info->map.y)
		tmp[j] = info->map.tab[j];
	if ((tmp[info->map.y] = ft_slab(info, line, i)) == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[info->map.y + 1] = NULL;
	if (info->map.y > 0)
		free(info->map.tab);
	info->map.tab = tmp;
	info->map.y++;
	if ((info->map.x = ft_slablen(info, line)) == -1)
		return (-13);
	printf("ok\n");
	return (0);
}
