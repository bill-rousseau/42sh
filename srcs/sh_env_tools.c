/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:31:05 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 19:31:08 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

t_env			*sh_init_env(char **envp)
{
	t_env		*env;
	t_env		*new;
	int			i;
	char		*tmp;

	env = NULL;
	i = 0;
	while (envp && envp[i])
		i++;
	while (--i >= 0)
		if ((tmp = ft_strchr(envp[i], '=')))
		{
			new = (t_env *)sh_malloc(sizeof(t_env));
			new->name = ft_strcdup(envp[i], '=');
			new->value = ft_strdup(tmp + 1);
			new->next = env;
			if (env && env->next)
				env->next->prev = env;
			env = new;
		}
	if (env)
		env->prev = NULL;
	sh_up_shlvl(env);
	return (env);
}

t_env			*sh_get_env_var(char *str)
{
	t_env		*tmp;

	tmp = g_env;
	while (tmp)
	{
		if (ft_strequ(str, tmp->name))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

char			**sh_getenv(void)
{
	t_env		*env;
	int			i;
	char		**tab;

	i = 0;
	env = g_env;
	while (env)
	{
		i++;
		env = env->next;
	}
	tab = (char **)sh_malloc((i + 1) * sizeof(char *));
	tab[i] = NULL;
	env = g_env;
	while (i)
	{
		tab[--i] = ft_strcjoin(env->name, env->value, '=');
		env = env->next;
	}
	return (tab);
}

void			sh_printenv(t_env *env)
{
	while (env)
	{
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->value);
		env = env->next;
	}
}

void			sh_up_shlvl(t_env *env)
{
	int			num;

	while (env && !ft_strequ(env->name, "SHLVL"))
		env = env->next;
	if (env)
	{
		num = ft_atoi(env->value);
		free(env->value);
		env->value = ft_itoa(num + 1, 10);
	}
}
