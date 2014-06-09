/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 18:38:44 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/16 18:38:46 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			sh_echo(char **args)
{
	int		i;
	int		state;

	i = 1;
	state = 0;
	if (args && args[0] && args[1] && ft_strequ(args[1], "-n"))
	{
		i++;
		state = 1;
	}
	while (args && args[0] && args[i])
	{
		if (!args[i + 1])
		{
			if (state)
				ft_putstr(args[i]);
			else
				ft_putendl(args[i]);
		}
		else
			ft_putstr(args[i]);
		i++;
	}
	return (0);
}
