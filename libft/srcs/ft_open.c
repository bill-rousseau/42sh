/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:53:28 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/22 18:53:32 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

int		ft_open(char *name, int opt)
{
	int		fd;

	if (name)
	{
		if ((fd = open(name, opt)) == -1)
		{
			ft_putendl("Open Failed");
			return (-1);
		}
		else
			return (fd);
	}
	ft_putendl("File name null.");
	return (-1);
}
