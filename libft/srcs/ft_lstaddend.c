/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 15:14:57 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/07 15:22:00 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = (t_list *)*alst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		new->next = NULL;
	}
}
