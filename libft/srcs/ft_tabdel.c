/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:05:17 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/29 19:05:24 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tabdel(char ***tab)
{
	unsigned int	i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	free(*tab);
	*tab = NULL;
}
