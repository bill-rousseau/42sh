/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 18:53:38 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 18:53:39 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "sh.h"

void		*sh_malloc(unsigned int size)
{
	void	*res;

	res = (void *)malloc(size);
	if (!res)
		sh_error_exit(1, NULL);
	return (res);
}

int			sh_putchar(int c)
{
	return (write(1, &c, 1));
}

char		**sh_tree_to_tab(t_lex *data)
{
	t_lex	*tmp;
	char	**args;
	int		i;

	tmp = data;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	args = (char **)sh_malloc((i + 1) * sizeof(char *));
	i = 0;
	while (data)
	{
		args[i] = ft_strdup(data->str);
		i++;
		data = data->next;
	}
	args[i] = NULL;
	return (args);
}
