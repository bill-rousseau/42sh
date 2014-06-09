/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 18:49:19 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 18:49:21 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "sh.h"

void		sh_exec_pipe(t_tree *tree)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if ((pid1 = sh_fork()) == 0)
	{
		if (pipe(pipefd) != 0)
			sh_error_exit(2, NULL);
		if ((pid2 = sh_fork()) == 0)
		{
			sh_pipe_child(tree, pipefd);
			exit(g_last_return);
		}
		else
		{
			sh_wait(pid2);
			sh_pipe_father(tree, pipefd);
		}
		exit(g_last_return);
	}
	else
		sh_wait(pid1);
}

void		sh_pipe_child(t_tree *tree, int pipefd[2])
{
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	sh_exec_tree(tree->left);
}

void		sh_pipe_father(t_tree *tree, int pipefd[2])
{
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	sh_exec_tree(tree->right);
}
