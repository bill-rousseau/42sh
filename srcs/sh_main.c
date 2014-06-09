/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 18:02:04 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 18:02:05 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

t_env				*g_env = NULL;
struct winsize		g_winsize;
struct termios		*g_backup_term;
t_fork				*g_fork = NULL;
unsigned int		g_last_return = 0;

int		main(int ac, char **av, char **envp)
{
	char		*line;
	t_tree		*cmd;

	(void)ac;
	(void)av;
	line = NULL;
	g_env = sh_init_env(envp);
	sh_init_winsize(&g_winsize);
	if (!g_env)
		sh_error(1, NULL);
	sh_signal();
	while (sh_prompt(&line))
	{
		if (line && *line)
			cmd = sh_analyze(line);
		if (cmd)
			sh_exec_tree(cmd);
		if (line && line[0] != '\0')
			sh_deltree(&cmd);
		ft_strdel(&line);
	}
	return (1);
}
