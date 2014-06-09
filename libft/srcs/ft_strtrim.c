/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:55:39 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/05 19:11:31 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t		ft_end(char *s, size_t i)
{
	size_t		end;

	end = i;
	while (s[i])
	{
		if (!ft_iswhite(s[i]))
			end = i;
		i++;
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*dest;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_iswhite(s[i]) && s[i])
		i++;
	start = i;
	end = ft_end((char *)s, start);
	dest = (char *)malloc(sizeof(char));
	if (start != end || (start == end && start != (size_t)ft_strlen(s)))
	{
		if (!(dest == (char *)malloc((end - start + 2) * sizeof(char))))
			return (NULL);
		ft_strncpy(dest, s + start, end - start + 1);
		dest[end - start + 1] = 0;
	}
	else if (start == end && start == (size_t)ft_strlen(s))
		*dest = '\0';
	return (dest);
}
