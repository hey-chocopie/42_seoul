/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:29:17 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/16 22:22:36 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#define BUFFER_SIZE 100

void	ft_result_save(char **result_save, int i, char **line, int fd)
{
	char		*tmp;

	result_save[fd][i] = 0;
	*line = ft_strdup(result_save[fd]);
	if (result_save[fd][i + 1] != 0)
	{
		tmp = ft_strdup((result_save[fd]) + i + 1);
		free(result_save[fd]);
		result_save[fd] = tmp;
	}
	else
	{
		free(result_save[fd]);
		result_save[fd] = 0;
	}
}

int		save_check(char **result_save, char **line, int fd)
{
	int			i;

	i = 0;
	while (result_save[fd] != 0)
	{
		if (result_save[fd][i] != '\n')
		{
			if (result_save[fd][i] == 0)
				break ;
			i++;
			if (result_save[fd][i] == 0)
				break ;
		}
		else
		{
			ft_result_save(result_save, i, line, fd);
			return (1);
		}
	}
	return (0);
}

int		ft_result_save2(char **result_save, char **line, char *tmp, int fd)
{
	int		i;

	i = 0;
	while (result_save[fd][i] != '\n' && result_save[fd][i])
		i++;
	if (result_save[fd][i] == '\n')
	{
		result_save[fd][i] = 0;
		*line = ft_strdup(result_save[fd]);
		tmp = ft_strdup(result_save[fd] + i + 1);
		free(result_save[fd]);
		if (tmp[0] == 0)
		{
			free(tmp);
			result_save[fd] = 0;
			return (1);
		}
		result_save[fd] = tmp;
		return (1);
	}
	return (0);
}

int		ft_read_print(int fd, char *buf, char **result_save, char **line)
{
	int			i;
	int			check;
	char		*tmp;

	i = 0;
	while (((check) = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[(check)] = 0;
		i = 0;
		if (result_save[fd] == 0)
			result_save[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(result_save[fd], buf);
			free(result_save[fd]);
			result_save[fd] = tmp;
		}
		i = 0;
		if (1 == (ft_result_save2(result_save, line, tmp, fd)))
			return (1);
	}
	return (check);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1]; //malloc으로 선언해서 사이즈를 주어주면 더 많이 가능함. 
	int				check;
	static	char	*result_save[1200];

	if (fd < 0 || line == 0 || (BUFFER_SIZE <= 0))
		return (-1);
	if (1 == save_check(result_save, line, fd))
		return (1);
	if ((check = ft_read_print(fd, buf, result_save, line)) == 1)
		return (1);
	if (check < 0)
		return (-1);
	*line = ft_strdup("");
	if (0 != result_save[fd])
	{
		free(*line);
		*line = ft_strdup(result_save[fd]);
	}
	free(result_save[fd]);
	result_save[fd] = 0;
	return (0);
}
