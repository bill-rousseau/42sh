/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 17:37:57 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/16 17:37:58 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int			sh_cd(char **args)
{
	int		error;
	t_env	*env;

	error = 0;
	if (!args[1] && (env = sh_get_env_var("HOME")))
		error = chdir(env->value);
	else if (args[2])
		sh_error(7, NULL);
	else if (ft_strequ(args[1], "-") && (env = sh_get_env_var("OLDPWD")))
		error = chdir(env->value);
	else
		error = chdir(args[1]);
	if (error == -1)
		sh_error(8, NULL);
	else
		sh_update_cd();
	return (-error);
}

void		sh_update_cd(void)
{
	char	*pwd;
	t_env	*old;

	old = sh_get_env_var("PWD");
	pwd = getcwd(NULL, 0);
	if (old)
		sh_exec_setenv("OLDPWD", old->value);
	sh_exec_setenv("PWD", pwd);
	free(pwd);
}
