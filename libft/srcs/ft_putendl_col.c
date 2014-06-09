/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 15:18:52 by shedelin          #+#    #+#             */
/*   Updated: 2014/04/30 15:18:54 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

int		ft_putendl_col(char *str, int color, char *state, int fd)
{
	if (!str)
		return (0);
	return (ft_putstr_col(str, color, state, fd) + ft_putchar_fd('\n', fd));
}
