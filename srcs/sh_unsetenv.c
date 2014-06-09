/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:54:29 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/16 18:54:30 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int		sh_unsetenv(char **args)
{
	int		i;

	i = 0;
	while (args && args[i])
		i++;
	if (i == 1)
		sh_error_str(4, NULL);
	else
	{
		i = 1;
		while (args[i])
			sh_exec_unsetenv(args[i++]);
	}
	return (1);
}

void	sh_exec_unsetenv(char *name)
{
	t_env	*env;

	env = sh_get_env_var(name);
	if (env && env == g_env)
	{
		free(g_env->name);
		free(g_env->value);
		env = g_env->next;
		free(g_env);
		g_env = env;
	}
	else if (env)
	{
		free(env->name);
		free(env->value);
		env->prev->next = env->next;
		if (env->next)
			env->next->prev = env->prev;
		free(env);
	}
	else
		sh_error(10, name);
}
