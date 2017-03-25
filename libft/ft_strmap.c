/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:29:36 by lfranco-          #+#    #+#             */
/*   Updated: 2017/02/28 20:29:37 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*ret;

	i = 0;
	l = 0;
	if (s)
	{
		while (s[l] != '\0')
			l++;
		ret = (char*)ft_memalloc(l + 1);
		if (ret)
		{
			while (i < l)
			{
				ret[i] = f(s[i]);
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (0);
}
