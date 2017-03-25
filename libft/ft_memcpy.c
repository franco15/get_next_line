/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:28:53 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/05 02:28:54 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p;
	const char	*s;

	s = src;
	p = dst;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*p++ = *s++;
	return (dst);
}
