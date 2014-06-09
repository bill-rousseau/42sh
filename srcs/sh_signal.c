/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:21:45 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 19:21:47 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

static void		sh_sigint(int sig)
{
	(void)sig;
}

void			sh_signal(void)
{
	signal(SIGINT, sh_sigint);
}
