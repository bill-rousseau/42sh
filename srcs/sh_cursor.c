/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 21:47:09 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/09 21:47:11 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "sh.h"

t_cursor	*sh_init_cursor(int len)
{
	t_cursor	*new;

	new = (t_cursor *)sh_malloc(sizeof(t_cursor));
	if (!new)
		sh_error_exit(1, NULL);
	new->start = sh_newchar('\0');
	new->current = new->start;
	new->end = new->start;
	new->pos_col = len;
	return (new);
}

t_char		*sh_newchar(char c)
{
	t_char		*new;

	new = (t_char *)sh_malloc(sizeof(t_char));
	if (!new)
		sh_error_exit(1, NULL);
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		sh_insert_char(t_cursor *cursor, char c)
{
	t_char	*new;

	new = sh_newchar(c);
	new->next = cursor->current;
	new->prev = cursor->current->prev;
	if (cursor->current == cursor->start)
		cursor->start = new;
	cursor->current->prev = new;
	if (new->prev)
		new->prev->next = new;
	cursor->pos_col += 1;
	if (cursor->pos_col == 0)
		tputs(tgetstr("do", NULL), 1, sh_putchar);
	write(1, &c, 1);
	if (cursor->current != cursor->end)
		sh_printlst(cursor);
}
