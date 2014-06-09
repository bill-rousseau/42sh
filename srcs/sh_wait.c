/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 20:47:55 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 20:47:56 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include "sh.h"

void		sh_wait(int pid)
{
	int		status;

	wait(&status);
	if (WIFEXITED(status))
		g_last_return = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
		g_last_return = 128 + WTERMSIG(status);
	if (WIFEXITED(status) || !WIFSTOPPED(status))
		sh_unset_fork(pid);
}
