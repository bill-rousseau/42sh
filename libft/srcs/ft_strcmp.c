/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:14:06 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 16:16:39 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (*((char *)s1 + i) == *((char *)s2 + i))
	{
		if (*((char *)s1 + i) == '\0')
			return (0);
		i++;
	}
	return (*((char *)s1 + i) - *((char *)s2 + i));
}
