/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:27:08 by lfranco-          #+#    #+#             */
/*   Updated: 2017/02/28 20:27:10 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int	r;
	int	n;

	r = 0;
	n = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			n = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = (r * 10) + (*str - 48);
		str++;
	}
	return (r * n);
}
