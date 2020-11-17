/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:50:12 by hoylee            #+#    #+#             */
/*   Updated: 2020/11/16 19:51:49 by hoylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1000


int get_next_line(int fd, char **line);

int main(){

		int fd;
		char *buf;
		int check;
		char *aa;
		int i;
		aa= (char *)malloc(sizeof(char)*1);
		i = 0;
		check = 1;
        fd=open("../map/1.cub",O_RDONLY);
		while(check != 0 && check != -1 )	
		{
			check = get_next_line(fd, &buf);
			printf("%s\n", buf);
			free(buf);

		}	
       close(fd);
}
