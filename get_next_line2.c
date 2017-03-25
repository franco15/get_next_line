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

char	*ft_lst2str(t_list **lst)
{
	int		l;
	char	*str;
	t_list	*tmp;

	tmp = *lst;
	l = 0;
	while (tmp != NULL)
	{
		l += ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	tmp = *lst;
	str = ft_memalloc(l);
	while (tmp != NULL)
	{
		l = ft_strlen(tmp->content);
		str = ft_strncat(str, tmp->content, l);
		tmp = tmp->next;
	}
	return (str);
}

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	get_next_line(const int fd, char **line)
{
	char		*buff;
	int			i;
	int			j;
	int			l;
	t_list		*start;
	t_list		*tmp;
	t_list		*tmp2;
	static char	*rem;

	if (rem)
	{
		i = 0;
		j = 0;
		while (rem[i] == '\n')
			j++;
		if (j > 1)
		{
			rem[0] = 0;
			rem++;
			return (1);
		}
		start = ft_lstnew(rem, ft_strlen(rem + 1));
		free(rem);
	}
	buff = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) == 0)
		return (0);
	if (!start)
		start = ft_lstnew(buff, BUFF_SIZE + 1);
	else
	{
		tmp2 = ft_lstnew(buff, BUFF_SIZE + 1);
		ft_lstaddback(&start, tmp2);
	}
	i = 0;
	while (i == 0)
	{
		read(fd, buff, BUFF_SIZE);
		if (ft_strchr(buff, '\n'))
		{
			l = ft_strlenc(buff, '\n');
			l = BUFF_SIZE - l;
			rem = ft_strnew(l);
			while (buff[i] != '\n')
				i++;
			j = 0;
			while (buff[++i] != '\0')
				rem[j++] = buff[i];
		}
		tmp = ft_lstnew(buff, ft_strlenc(buff, '\n') + 1);
		ft_lstaddback(&start, tmp);
	}
	*line = ft_lst2str(&start);
	free(buff);
	return (1);
}
