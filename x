int	get_next_line(const int fd, char **line)
{
	char	*buff;
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	buff = ft_strnew(BUFF_SIZE);
	while (i == 0)
	{
		read(fd, buff, BUFF_SIZE);
		if (ft_strchr(buff, '\n'))
			i++;
		l += ft_strlenc(buff, '\n');
	}
	printf("len: %zu\n", l);
	*line = ft_strnew(l);
	i = 0;
	while (i == 0)
	{
		read(fd, buff, BUFF_SIZE);
		if (ft_strchr(buff, '\n'))
			i++;
		*line = ft_strncat(*line, buff, (ft_strlenc(buff, '\n') + 1));
	}
	free(buff);
	return (1);
}

char	*otroalloc(char *s, size_t l)
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
//	while (l + i > j)
//		ret[j++] = '\0';
	ret = ft_strcpy(ret, s);
	return (ret);
}
