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

st_list	*newelem(int fd)
{
	st_list	*elem;

	if(!(elem = ft_memalloc(sizeof(st_list))))
		return (0);
	elem->w = 0;
	elem->fd = fd;
	return (elem);
}

void	setrem(st_list *file, char *buff)
{
	while (*buff != '\n')
		buff++;
	file->rem = ft_strcpy(file->rem, buff);
	file->w = 1;
}

char	*readfd(st_list *file, int fd)
{
	char	*buff;
	char	*tmp;
	buff = ft_strnew(BUFF_SIZE);
	if (file->rem)
	{
		if (file->rem[0] == '\n')
		{
			tmp = file->rem + 1;
			file->rem = tmp;
			return (0);
		}
		file->content = file->rem;
	}
	while(file->w == 0)
	{
		read(fd, buff, BUFF_SIZE);
		if (ft_strchr(buff, '\n'))
			setrem(file, buff);
		file->content = ft_realloc(file->content, ft_strlen(file->content) + 1,
									ft_strlen(file->content) + BUFF_SIZE + 1);
		file->content = ft_strncat(file->content, buff, ft_strlenc(buff, '\n'));
	}
	return (file->content);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	**files;
	int					i;

	if (!fd || !line)
		return (-1);
	if (!files)
		files = ft_lstnew(newelem(fd), sizeof(st_list));
	i = 0;
	while (files[i]->fd != fd)
		i++;
	if (files[i]->fd != fd)
	{
		files = ft_realloc(files, ft_strlen(files), ft_strlen(files) + 1);
		files[++i] = ft_lstnew(newelem(fd), sizeof(st_list));
		ft_lstadd()
	}
	if (!(line = readfd(files[i]->content, fd)))
		return (0);
	return (1);
}
