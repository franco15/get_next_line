/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:14:30 by lfranco-          #+#    #+#             */
/*   Updated: 2017/02/28 18:14:31 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1024

typedef struct		s_line
{
	char			*rem;
	char			*ln;
	size_t			size;
	int				w;
}					t_line;

typedef struct		s_file
{
	t_line			*content;
	int				fd;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
