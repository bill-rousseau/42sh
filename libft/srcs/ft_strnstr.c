/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:12:16 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 20:05:33 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	if (*s2 == 0)
		return ((char*)s1);
	i = 0;
	while (i < n && *(s1 + i))
	{
		j = 0;
		while (*(s1 + i + j) == *(s2 + j) && i + j < n)
		{
			if (*(s2 + j + 1) == 0)
				return ((char*)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
