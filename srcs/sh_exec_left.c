/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 21:00:53 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 21:00:55 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

void		sh_exec_left(t_tree *tree)
{
	int		fd;
	int		tmp_fd;

	if (tree->right->type != _word)
	{
		sh_error(5, NULL);
		return ;
	}
	if (!(fd = sh_open(tree->right->list->str)))
		return ;
	tmp_fd = dup(0);
	dup2(fd, 0);
	sh_exec_tree(tree->left);
	dup2(tmp_fd, 0);
	close(fd);
}

int			sh_open(char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		sh_error_str(3, file);
		return (0);
	}
	return (fd);
}
