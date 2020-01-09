/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpet <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:40:25 by rpet          #+#    #+#                 */
/*   Updated: 2020/01/09 09:01:43 by rpet          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //norm

int		strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*strdup_gnl(char *str)
{
	char	*ret;
	int		i;

	if (str == NULL)
		return (NULL);
	i = strlen_gnl(str);
	ret = malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		len3;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = strlen_gnl(s1);
	len2 = strlen_gnl(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);
	result[len1 + len2] = '\0';
	len3 = 0;
	while (len3 < len1 + len2)
	{
		if (len3 < len1)
			result[len3] = s1[len3];
		else
			result[len3] = s2[len3 - len1];
		len3++;
	}
	free(s1);
	return (result);
}

int		strchr_gnl(char *str, char c)
{
	int		i;

	i = 0;
	if (str[0] == c)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*substr_gnl(char *str, int len)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
//	len = (len > i) ? len : i;
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
