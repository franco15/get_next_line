/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:45:43 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/02 16:45:45 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p;
	size_t	l;

	l = ft_strlen(src);
	p = dst;
	if (len > l)
	{
		while (*src)
		{
			*p++ = *src++;
			len--;
		}
		while (len-- > 0)
			*p++ = '\0';
	}
	else
		while (len-- > 0)
			*p++ = *src++;
	return (dst);
}
