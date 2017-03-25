/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 23:39:54 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/04 23:39:55 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static void	*alloc(int n)
{
	char	*s;

	if (n >= 0)
		if (!(s = (char*)ft_memalloc(n + 1)))
			return (0);
	if (n < 0)
		if (!(s = (char*)ft_memalloc(n + 2)))
			return (0);
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = len(n);
	j = 0;
	if (!(s = alloc(i--)))
		return (0);
	if (n < 0)
	{
		s[j++] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		s[i--] = ((n % 10) + 48);
		n /= 10;
		j++;
	}
	s[i] = (n + 48);
	s[++j] = '\0';
	return (s);
}
