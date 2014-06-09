/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lst_lex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:29:32 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/13 22:29:34 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

void		sh_dellex(t_lex **l_lex)
{
	t_lex	*tmp;
	t_lex	*tmp2;

	tmp = *l_lex;
	while (tmp)
	{
		ft_strdel(&tmp->str);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int			sh_lexlen(t_lex *lst)
{
	t_lex	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

t_lex		*sh_newlex(t_auto *autom)
{
	t_lex	*elem;

	if (!(elem = (t_lex *)sh_malloc(sizeof(t_lex))))
		return (NULL);
	elem->type = autom->status;
	if (!(elem->str = ft_strdup(autom->buf)))
	{
		free(elem);
		return (NULL);
	}
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void		sh_lexadd(t_lex **list, t_lex *elem)
{
	t_lex	*tmp;

	tmp = *list;
	if (!tmp)
	{
		*list = elem;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
	elem->prev = tmp;
}
