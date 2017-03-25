/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:05:17 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/04 22:05:18 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	if (!(r = (char**)ft_memalloc(sizeof(char*) * ft_countwords(s, c) + 1)))
		return (0);
	while (i < (ft_countwords(s, c)))
	{
		j = 0;
		r[i] = ft_memalloc(ft_wordlen(s, c, k) + 1);
		while (s[k] == c && s[k] != '\0')
			k++;
		while (s[k] != c && s[k] != '\0')
			r[i][j++] = s[k++];
		r[i][j] = '\0';
		i++;
	}
	r[i] = 0;
	return (r);
}
