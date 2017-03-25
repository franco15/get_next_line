/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:09:08 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/06 23:09:09 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *p;
	t_list *t;

	p = *alst;
	while (p)
	{
		t = p;
		del(p->content, p->content_size);
		free(p);
		p = t->next;
	}
	*alst = NULL;
}
