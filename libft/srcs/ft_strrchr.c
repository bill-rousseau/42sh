/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:14:24 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 22:26:46 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)s + size);
	while (i < size)
	{
		if (s[size - i] == (char)c)
			return ((char *)(s + (size - i)));
		i++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
