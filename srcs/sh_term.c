/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:45:49 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 19:45:51 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include <termios.h>
#include "sh.h"

int			sh_init_term(void)
{
	t_env			*env_term;
	char			buffer[4096];
	struct termios	term;

	env_term = sh_get_env_var("TERM");
	if (env_term && env_term->value && tgetent(buffer, env_term->value) != 1)
	{
		sh_error(2, env_term->value);
		return (1);
	}
	if (!env_term)
	{
		sh_error(2, NULL);
		return (1);
	}
	tcgetattr(0, &term);
	tcgetattr(0, g_backup_term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, &term);
	return (0);
}

void		sh_exit_term(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag |= ECHO;
	term.c_lflag |= ICANON;
	tcsetattr(0, 0, &term);
}
