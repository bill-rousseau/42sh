/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:43:21 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/01 17:58:51 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static void		ft_dellist(t_list **lst)
{
	if (*lst)
	{
		ft_dellist(&(*lst)->next);
		free((*lst)->content);
		(*lst)->content = NULL;
		free(*lst);
		*lst = NULL;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;

	list = NULL;
	while (lst)
	{
		new = NULL;
		new = ft_lstnew(f(lst), sizeof(f(lst)));
		if (!new)
		{
			ft_dellist(&list);
			return (list);
		}
		ft_lstadd(&list, new);
		lst = lst->next;
		ft_memdel((void *)&new->content);
		ft_memdel((void *)&new);
	}
	return (list);
}
