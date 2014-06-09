/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 22:16:07 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/09 22:16:08 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

void		sh_printlst(t_cursor *cursor)
{
	int		nb;
	t_char	*tmp;

	tmp = cursor->current;
	nb = 0;
	tputs(tgetstr("sc", NULL), 1, sh_putchar);
	while (tmp)
	{
		write(1, &(tmp->c), 1);
		tmp = tmp->next;
		if (cursor->pos_col % (int)g_winsize.ws_col == 0)
			nb++;
	}
	while (nb--)
		tputs(tgetstr("up", NULL), 1, sh_putchar);
	tputs(tgetstr("rc", NULL), 1, sh_putchar);
}
