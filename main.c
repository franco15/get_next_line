#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>	//open
#include <unistd.h>	// close

int main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
//		ft_putstr("tercer:");
		ft_putnbr(ret);
		ft_putstr(":");
		ft_putstr(line);
		ft_putendl(".");
	}
	ft_putnbr(ret);
	close(fd);
	if (line)
		return (-1);
	return (0);
}
