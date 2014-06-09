/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:54:45 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 21:22:02 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		dest = (char *)malloc((len + 1) * sizeof(*s));
		if (dest == NULL)
			return (NULL);
		while (i < len && s[start + i] != '\0')
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
