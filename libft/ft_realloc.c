#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t newsize)
{
	void	*new;
	size_t	i;

	i = 0;
	if (ptr && newsize && size)
	{
		new = ft_memalloc(newsize);
		new = ft_memcpy(new, ptr, size);
		free(ptr);
	}
	else
		new = ft_memalloc(newsize);
	return (new);
}
