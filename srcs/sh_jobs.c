/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:50:05 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/16 18:50:06 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh.h"

int			sh_jobs(char **args)
{
	t_fork		*tmp;

	(void)args;
	tmp = g_fork;
	while (tmp)
	{
		ft_putnbr(tmp->pid);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	return (0);
}
