/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:17:28 by hoylee            #+#    #+#             */
/*   Updated: 2020/07/05 22:28:56 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nn;
	int				max;
	char			save;

	nn = (long long int)n;
	max = 1000000000;
	if (nn < 0)
	{
		write(fd, "-", 1);
		nn = nn * -1;
	}
	while (nn / max == 0 && max > 1)
		max = max / 10;
	while (max >= 1)
	{
		save = (nn / max) + '0';
		write(fd, &save, 1);
		nn = nn % max;
		max = max / 10;
	}
}
