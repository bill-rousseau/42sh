/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:04:54 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 22:25:10 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + i))
	{
		if ((char)c == *(s + i))
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	return (NULL);
}
