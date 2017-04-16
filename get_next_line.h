#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include "./libft/libft.h"

#define BUFF_SIZE 1024

typedef struct		t_line
{
	char			*rem;
	char			*ln;
	size_t			size;
	int				w;
}					t_line;

typedef struct		t_file
{
	t_line			*content;
	int				fd;
}					t_file;

int	get_next_line(const int fd, char **line);

#endif
