/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:56:04 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/02 19:56:05 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2 && (ret = ft_memalloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			ret[i++] = s2[j++];
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
