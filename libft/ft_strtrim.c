/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:11:17 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/02 20:11:18 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s)
		return (0);
	while ((ft_isspace(*s) == 1))
		s++;
	if (!*s)
		return (ft_strnew(0));
	ret = (char*)(s + (ft_strlen(s) - 1));
	while (ft_isspace(*ret))
		ret--;
	return (ft_strsub(s, 0, (ret - s + 1)));
}
