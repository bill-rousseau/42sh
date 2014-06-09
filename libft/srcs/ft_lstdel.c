/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:39:09 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 17:10:41 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*mem;

	if (!(alst == NULL || del == NULL))
	{
		lst = *alst;
		while (lst != NULL)
		{
			mem = lst->next;
			del(lst->content, lst->content_size);
			lst->next = NULL;
			free(lst);
			lst = mem;
		}
		*alst = NULL;
	}
}
