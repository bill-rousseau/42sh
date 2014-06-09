/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 14:26:41 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/01 22:44:22 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == 0)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new->content = (void *)malloc(content_size * sizeof(char));
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
