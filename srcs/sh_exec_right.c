/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 21:16:39 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 21:16:41 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

void	sh_exec_right(t_tree *tree)
{
	int		fd;
	int		tmp_fd;

	if (!(fd = sh_get_fd(tree)))
		return ;
	tmp_fd = dup(1);
	dup2(fd, 1);
	sh_exec_tree(tree->left);
	dup2(tmp_fd, 1);
	close(fd);
}

int		sh_get_fd(t_tree *tree)
{
	int		fd;
	char	*file;
	t_tree	*tmp;
	char	*token;

	token = tree->list->str;
	tmp = tree->right;
	while (tmp && tmp->type == _right)
	{
		file = tmp->left->list->str;
		if (!(fd = sh_open2(file, tmp->list->str)))
			return (0);
		token = tmp->list->str;
		tmp = tmp->right;
		close(fd);
	}
	file = tmp->list->str;
	fd = sh_open2(file, token);
	return (fd);
}

int		sh_open2(char *file, char *type)
{
	int		fd;

	if (type && type[1])
	{
		if ((fd = open(file, O_CREAT | O_APPEND | O_WRONLY, RIGHTS)) < 0)
		{
			sh_error_str(3, file);
			return (0);
		}
	}
	else
	{
		if ((fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, RIGHTS)) < 0)
		{
			sh_error_str(3, file);
			return (0);
		}
	}
	return (fd);
}
