/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 16:04:52 by rpet          #+#    #+#                 */
/*   Updated: 2020/01/10 09:35:25 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>

int		main(void)
{
	int		fd1;
	int		fd2;
	int		ret;
	int		ret_end;
	int		i;
	int		cur_fd;
	char	*line;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	ret = 1;
	ret_end = 1;
	i = 0;
/*	while (ret == 1)
	{
		ret = get_next_line(fd2, &line);
		printf("GNL: [%i] %s\n", ret, line);
		i++;
		free(line);
	}*/
	while (ret == 1 || ret_end == 1)
	{
		ret = ret_end;
		cur_fd = (i % 2 == 1) ? fd1 : fd2;
		ret_end = get_next_line(cur_fd, &line);
		printf("FD%i: [%i] %s\n", cur_fd, ret_end, line);
		i++;
		free(line);
	}
//	while (1);
	return (0);
}
