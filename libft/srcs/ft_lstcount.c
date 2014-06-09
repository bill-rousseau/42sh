/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 22:52:00 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 22:52:02 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *list)
{
	int		len;
	t_list	*tmp;

	len = 0;
	if (list)
	{
		tmp = list;
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
	}
	return (len);
}
