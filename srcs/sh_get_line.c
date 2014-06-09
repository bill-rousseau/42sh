/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 21:43:58 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/09 21:44:00 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

char		*sh_get_line(int len)
{
	char		key[4];
	t_cursor	*cursor;
	char		*line;

	ft_bzero(key, 4);
	cursor = sh_init_cursor(len);
	while (read(0, key, 4) != -1 && !(K0 == 10 && K1 == 0 && K2 == 0))
	{
		sh_execkey(key, cursor);
		ft_bzero(key, 4);
	}
	line = sh_convert(cursor);
	sh_del_lstchar(cursor);
	free(cursor);
	return (line);
}

char		*sh_convert(t_cursor *cursor)
{
	int		len;
	t_char	*tmp;
	char	*str;

	len = 1;
	tmp = cursor->start;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	str = (char *)sh_malloc(len * sizeof(char));
	tmp = cursor->start;
	len = 0;
	while (tmp)
	{
		str[len] = tmp->c;
		len++;
		tmp = tmp->next;
	}
	return (str);
}

void		sh_del_lstchar(t_cursor *cursor)
{
	t_char		*tmp;
	t_char		*todel;

	tmp = cursor->start;
	while (tmp)
	{
		todel = tmp;
		tmp = tmp->next;
		free(todel);
	}
}
