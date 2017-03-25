/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 23:34:37 by lfranco-          #+#    #+#             */
/*   Updated: 2017/03/06 23:34:38 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*t;
	t_list	*r;

	if (!lst || !f)
		return (0);
	t = f(lst);
	r = ft_lstnew(t->content, t->content_size);
	if (r)
	{
		new = r;
		lst = lst->next;
		while (lst != NULL)
		{
			t = f(lst);
			if (!(new->next = ft_lstnew(t->content, t->content_size)))
				return (0);
			new = new->next;
			lst = lst->next;
		}
	}
	return (r);
}
