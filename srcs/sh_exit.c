/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 15:13:36 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/13 15:13:38 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int		sh_exitshell(char **args)
{
	ft_putendl_col("exit", WHITE, NORMAL, 1);
	if (args && args[0] && args[1])
		exit(ft_atoi(args[1]));
	exit(g_last_return);
	return (1);
}
