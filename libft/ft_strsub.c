/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:26:09 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/01 17:26:10 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*c;
	unsigned int	i;

	i = 0;
	if (s && (c = ft_memalloc(len + 1)))
	{
		while (s[start] != '\0' && len--)
			c[i++] = s[start++];
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
