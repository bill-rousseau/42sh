/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:44:33 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 19:23:40 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!(s1 == NULL || s2 == NULL))
	{
		while (s1[i] == s2[i] && i < n)
		{
			if (s1[i] == '\0')
				return (1);
			i++;
		}
	}
	if (n == i)
		return (1);
	return (0);
}
