/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:23:56 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/26 15:24:24 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*ft_strdup(const char *s1);
void		ft_length(int *i, int *j, char const *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif
