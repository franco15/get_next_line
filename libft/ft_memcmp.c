/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 01:40:15 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/06 01:40:16 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (!p1 && !p2)
		return (0);
	while (n--)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
			return (*p1 - *p2);
	}
	return (0);
}
