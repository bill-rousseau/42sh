/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_movecursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 22:28:23 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/09 22:28:25 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <stdlib.h>
#include "sh.h"

void		sh_movecursor(t_cursor *cursor, char *key)
{
	if (cursor->current->next && K2 == 67)
	{
		if (cursor->pos_col % g_winsize.ws_col == 0)
			tputs(tgetstr("do", NULL), 1, sh_putchar);
		else
			tputs(tgetstr("nd", NULL), 1, sh_putchar);
		cursor->pos_col += 1;
		cursor->current = cursor->current->next;
	}
	else if (cursor->current->prev && K2 == 68)
	{
		cursor->pos_col -= 1;
		cursor->current = cursor->current->prev;
		tputs(tgetstr("le", NULL), 1, sh_putchar);
	}
}
