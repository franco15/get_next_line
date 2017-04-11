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

t_file	*newelem(int fd)
{
	t_file	*elem;

	if(!(elem = ft_memalloc(sizeof(t_file))))
		return (0);
	elem->content = ft_memalloc(sizeof(t_line));
	elem->fd = fd;
	elem->content->w = 0;
	return (elem);
}

void	return_line(t_line *tmp, char *buff, char **line)
{
	size_t	i;
	char	*rd;

	if((rd = ft_strchr(buff, '\n')))
	{
		tmp->rem = ft_strdup(rd + 1);
		*line = NULL;
		tmp->w = 1;
	}
	else
	{
		tmp->ln = ft_realloc(tmp->ln, tmp->size, tmp->size + BUFF_SIZE + 1);
		tmp->size = ft_strlen(tmp->ln);
		(void)ft_strcat(tmp->ln, buff);
	}

}
/*
t = ft_strndup(buff, i + 1);
tmp->ln = ft_realloc(tmp->ln, tmp->size, tmp->size + i);
tmp->ln = ft_strncat(tmp->ln, t, i + 1);
tmp->size = ft_strlen(tmp->ln);
*line = tmp->ln;
tmp->ln = ft_realloc(tmp->ln, tmp->size, ft_strlen(tmp->rem));
tmp->ln = ft_strcpy(tmp->ln, tmp->rem);
*/
/*
t = ft_strndup(&tmp->rem[1], ft_strlen(&tmp->rem[1]));
tmp->rem = ft_realloc(t, ft_strlen(tmp->rem), ft_strlen(t));
*/
int		read_line(t_file *l, char **line)
{
	char	*buff;
	t_line	*tmp;
	char	*rd;
	long	i;

	buff = ft_strnew(BUFF_SIZE);
	tmp = l->content;
	while (tmp->w == 0)
	{
		if (tmp->rem)
		{
			(void)ft_strcat(buff, tmp->rem);
			ft_strdel(&tmp->rem);
			tmp->rem = 0;
		}
		else if ((i = read(l->fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		return_line(tmp, buff, line);
		ft_bzero(buff, BUFF_SIZE);
	}
	*line = tmp->ln;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*node;
	t_file			*file;

	if (!fd || !line)
		return (-1);
	if (!list)
		list = ft_lstnew(newelem(fd), sizeof(t_list));
	node = list;
	while (node)
	{
		file = node->content;
		if (file->fd == fd)
			return(read_line(file, line));
		node = node->next;
	}
	node = ft_lstnew(newelem(fd), sizeof(t_list));
	return (read_line(node->content, line));
}
