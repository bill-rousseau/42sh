/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:39:33 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 16:01:08 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s1 + i) = *((char *)s2 + i);
		if (*((char *)s2 + i) == c)
			return ((void *)(char *)s1 + i + 1);
		i++;
	}
	return (NULL);
}
