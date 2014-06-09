/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 22:22:56 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 22:22:58 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

void		sh_exec_cmd(char **args, char *path)
{
	char	*bin;

	if (args && args[0])
	{
		if (args[0][0] == '.' || args[0][0] == '/')
		{
			if (sh_testaccess(args[0]))
				execve(args[0], args, sh_getenv());
			else
				sh_error_str(3, args[0]);
			exit(1);
		}
		else
		{
			bin = sh_get_bin(args[0], path);
			if (bin)
				execve(bin, args, sh_getenv());
			sh_error(6, args[0]);
			ft_strdel(&bin);
			exit(1);
		}
	}
}

int			sh_testaccess(char *bin)
{
	if (access(bin, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

char		*sh_get_bin(char *args, char *path_env)
{
	char	**path;
	char	*tmp;
	int		i;

	if (args)
	{
		if (args[0] == '.' || args[0] == '/')
			return (args);
		path = ft_strsplit(path_env, ':');
		i = -1;
		while (path && path[++i])
		{
			tmp = ft_strcjoin(path[i], args, '/');
			if (sh_testaccess(tmp))
				break ;
			ft_strdel(&tmp);
		}
		if (path)
			ft_tabdel(&path);
		return (tmp);
	}
	else
		return (NULL);
}
