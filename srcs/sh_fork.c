/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 19:49:42 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 19:49:49 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int		sh_fork(void)
{
	t_fork		*new;
	int			child;

	child = fork();
	if (child == -1)
		sh_error(4, NULL);
	else if (child != 0)
	{
		new = (t_fork *)sh_malloc(sizeof(t_fork));
		new->pid = child;
		new->next = g_fork;
		g_fork = new;
		return (child);
	}
	return (0);
}

int		sh_unset_fork(int pid)
{
	t_fork		*lst;
	t_fork		*prev;

	lst = g_fork;
	prev = NULL;
	while (lst)
	{
		if (lst->pid == pid)
		{
			if (lst->next && prev)
				prev->next = lst->next;
			if (g_fork == lst)
				g_fork = NULL;
			free(lst);
		}
		prev = lst;
		lst = lst->next;
	}
	return (0);
}
