/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:26:10 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 19:26:11 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <get_next_line.h>
#include "sh.h"

int			sh_prompt(char **line)
{
	static int		i = 0;
	int				len;

	sh_prompt_pwd();
	if (i == 0)
		i = sh_init_term();
	len = 0;
	len += sh_prompt_user();
	if (len)
		len += ft_putstr_col("@", CYAN, NORMAL, 1);
	len += sh_prompt_host();
	len += ft_putstr_col(" $", YELLOW, BOLD, 1);
	if (i == 0)
	{
		*line = sh_get_line(len);
		sh_exit_term();
	}
	else
		get_next_line(0, line);
	ft_putchar('\n');
	return (len);
}

void		sh_prompt_pwd(void)
{
	t_env	*pwd;
	t_env	*home;
	char	*tmp;

	pwd = sh_get_env_var("PWD");
	home = sh_get_env_var("HOME");
	tmp = NULL;
	if (home && pwd)
		tmp = ft_strstr(pwd->value, home->value);
	if (tmp)
	{
		ft_putchar_col('~', BLACK, BOLD, 1);
		ft_putendl_col(tmp + ft_strlen(home->value), BLACK, BOLD, 1);
	}
	else if (pwd)
		ft_putendl_col(pwd->value, CYAN, BOLD, 1);
}

int			sh_prompt_user(void)
{
	t_env	*usr;

	usr = sh_get_env_var("USER");
	if (usr)
		return (ft_putstr_col(usr->value, CYAN, NORMAL, 1));
	return (0);
}

int			sh_prompt_host(void)
{
	char	*name;
	int		i;

	name = ft_strnew(1024);
	gethostname(name, 1024);
	i = 0;
	while (name[i] && name[i] != '.')
		ft_putchar_col(name[i++], CYAN, NORMAL, 1);
	ft_strdel(&name);
	return (i);
}
