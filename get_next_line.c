/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:54:11 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/19 17:54:14 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *s, size_t l)
{
	int		i;
	int		j;
	char	*ret;

	if (!s)
	{
		ret = ft_strnew(l);
		return (ret);
	}
	i = ft_strlen(s);
	ret = ft_strnew(l + i);
	j = 0;
	ret = ft_strcpy(ret, s);
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	*rem;
	char		*buff;
	char		*tmp;
	int			i;
	int			j;

	if (rem)
	{
		i = 0;
		j = 0;
		while (rem[i++] == '\n')
			j++;
		if (j > 1)
		{
			rem++;
			return (1);
		}
		tmp = ft_strdup(rem);
		free(rem);
	}
	i = 0;
	if (!tmp)
	{
		buff = ft_strnew(BUFF_SIZE);
		if ((read(fd, buff, BUFF_SIZE) == 0))
			return (0);
		if (ft_strchr(buff, '\n'))
		{
			while (buff[i] != '\n')
				i++;
			rem = ft_strdup(&buff[i]);
			tmp = ft_strndup(tmp, ft_strlenc(buff, '\n'));
			*line = tmp;
			return (1);
		}
		tmp = ft_strdup(buff);
	}
	while (i == 0)
	{
		buff = ft_strnew(BUFF_SIZE);
		if ((read(fd, buff, BUFF_SIZE) == 0))
			return (0);
		if (ft_strchr(buff, '\n'))
		{
			while (buff[i] == '\n')
				i++;
			rem = ft_strdup(&buff[i]);
		}
		tmp = ft_realloc(tmp, ft_strlenc(buff, '\n'));
		tmp = ft_strcat(tmp, &buff[i]);
	}
	*line = tmp;
	printf("1\n");
	free(buff);
	return (1);
}
