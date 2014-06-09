/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 17:02:23 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/08 17:13:07 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **list, t_list *ptr, t_list *ptr2)
{
	t_list	*tmp;

	tmp = *list;
	if (*list == ptr)
	{
		ptr->next = ptr2->next;
		ptr2->next = ptr;
		*list = ptr2;
	}
	else
	{
		while (tmp->next != ptr)
			tmp = tmp->next;
		tmp->next = ptr2;
		ptr->next = ptr2->next;
		ptr2->next = ptr;
	}
}
