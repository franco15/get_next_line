/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 04:25:13 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/06 04:25:14 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char*)s + i);
	while (s[i] != (char)c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char*)s + i);
}
