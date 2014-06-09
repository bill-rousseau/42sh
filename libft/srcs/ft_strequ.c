/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:38:39 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 21:13:56 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!(s1 == NULL || s2 == NULL))
	{
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (1);
			i++;
		}
		return (0);
	}
	return (0);
}
