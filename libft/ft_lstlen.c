/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:37:23 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/06 23:37:24 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *begin_list)
{
	t_list	*newelem;
	int		l;

	l = 0;
	newelem = begin_list;
	while (newelem)
	{
		newelem = newelem->next;
		l++;
	}
	return (l);
}
