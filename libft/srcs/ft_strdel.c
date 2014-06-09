/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:52:31 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 16:52:05 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		ft_bzero(*as, ft_strlen(*as));
		free(*as);
		*as = NULL;
	}
}
