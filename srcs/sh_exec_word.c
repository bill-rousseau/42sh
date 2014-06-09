/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 21:49:09 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 21:49:11 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "sh.h"

void		sh_exec_word(t_tree *tree)
{
	int		pid;
	int		i;
	char	**args;
	t_env	*path;

	args = sh_tree_to_tab(tree->list);
	if (args && (i = sh_is_builtin(args[0])) != -1)
		g_last_return = sh_exec_builtins(args, i);
	else
	{
		if ((pid = sh_fork()) == 0)
		{
			path = sh_get_env_var("PATH");
			if (path)
				sh_exec_cmd(args, path->value);
			else
				sh_exec_cmd(args, NULL);
		}
		else
			sh_wait(pid);
	}
	ft_tabdel(&args);
}

int			sh_is_builtin(char *name)
{
	int				i;
	static char		*builtins[] =

	{
	"cd",
	"env",
	"exit",
	"setenv",
	"unsetenv",
	"echo",
	"jobs",
	NULL,
	};
	i = 0;
	while (builtins[i] && !ft_strequ(builtins[i], name))
		i++;
	if (!builtins[i])
		return (-1);
	return (i);
}

int			sh_exec_builtins(char **args, int i)
{
	static t_builtin_fct	tab_builtin_fct[] =

	{
	&sh_cd,
	&sh_env,
	&sh_exitshell,
	&sh_setenv,
	&sh_unsetenv,
	&sh_echo,
	&sh_jobs,
	NULL,
	};
	return (tab_builtin_fct[i](args));
}
