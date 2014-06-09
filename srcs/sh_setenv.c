/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 17:56:29 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/16 17:56:31 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int		sh_setenv(char **args)
{
	int		i;

	i = 0;
	while (args && args[i])
		i++;
	if (i != 2 && i != 3)
		sh_error(9, NULL);
	else
	{
		if (args[2])
			sh_exec_setenv(args[1], args[2]);
		else
			sh_exec_setenv(args[1], "");
	}
	return (1);
}

void	sh_exec_setenv(char *name, char *value)
{
	t_env	*env;
	t_env	*new;

	env = sh_get_env_var(name);
	if (env)
	{
		free(env->value);
		env->value = ft_strdup(value);
	}
	else if (!env)
	{
		env = g_env;
		while (env && env->next)
			env = env->next;
		new = (t_env *)malloc(sizeof(t_env));
		new->name = ft_strdup(name);
		new->value = ft_strdup(value);
		new->prev = env;
		new->next = NULL;
		if (env)
			env->next = new;
		else
			g_env = new;
	}
}
