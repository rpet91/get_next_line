/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:35:57 by rpet          #+#    #+#                 */
/*   Updated: 2020/01/09 09:01:45 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h> //norm

static int	ret_value(char **str, int ret, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	ret += (str[fd][0] == '\n') ? 1 : 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	printf("ret value: [%i]\n", ret);
	if (str[fd][i] == '\n')
	{
		tmp = substr_gnl(str[fd] + i + 1, strlen_gnl(str[fd]);
//		printf("tmp: %s\n", tmp);
		if (tmp == NULL)
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		printf("str als tmp: [%s]\n", str[fd]);
		return (1);
	}
	free(str[fd]);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		str[fd][0] = '\0';
	}
	//line gaat fout omdat ie str moet overnemen. maar stopt als ie een \n tegenkomt
	//bij een te grote buffsize blijft er dus een stukje str over, wat daarna gaat 
	//zweven.`
	*line = substr_gnl(str[fd], strlen_gnl(str[fd]));
	if (str[fd] == NULL)
		return (-1);
	ret = 1;
//	printf("str voor read: %s\n", str[fd]);
	while (ret > 0 && strchr_gnl(str[fd], '\n') == -1)
	{
		ret = read(fd, str[fd], BUFFER_SIZE);
		str[fd][ret] = '\0';
	//	printf("str na read: [%s]\n", str[fd]);
	//	if (*line == NULL)
	//		*line = strdup_gnl(str[fd]);
	//	else
		*line = strjoin_gnl(*line, str[fd]);
	}
	printf("line na read: %s\n", *line);
	printf("str na read: [%s]\n", str[fd]);
	return (ret_value(str, ret, fd));
}
