/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:14:21 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/16 18:14:22 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int			sh_env(char **args)
{
	int		pid;
	int		i;
	char	*path;
	t_env	*env;

	if (args && args[0] && !args[1])
		sh_printenv(g_env);
	else if (args && args[0] && args[1] && ft_strequ(args[1], "-i") && !args[2])
		sh_printenv(NULL);
	else if (args && args[0] && args[1])
	{
		if ((env = sh_get_env_var("PATH")))
			path = env->value;
		else
			path = NULL;
		if ((pid = sh_fork()) == 0)
		{
			i = ft_strequ(args[1], "-i") ? 2 : 1;
			sh_modif_env(args, &i, path);
			exit(0);
		}
		else
			sh_wait(pid);
	}
	return (0);
}

void		sh_modif_env(char **args, int *i, char *path)
{
	char	*tmp;

	g_env = *i == 1 ? g_env : NULL;
	while (args[*i] && ft_strchr(args[*i], '='))
	{
		tmp = ft_strcdup(args[*i], '=');
		sh_exec_setenv(tmp, ft_strchr(args[*i], '=') + 1);
		ft_strdel(&tmp);
		(*i)++;
	}
	if (args[*i])
	{
		args[*i] = sh_get_bin(args[*i], path);
		sh_exec_cmd(args + *i, path);
	}
	else
		sh_printenv(g_env);
}
