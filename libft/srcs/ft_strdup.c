/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:49:36 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 21:13:24 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	dest = NULL;
	if (s1 != NULL)
	{
		len = ft_strlen(s1);
		dest = (char *)malloc((len + 1) * sizeof(char));
		if (dest != NULL)
			ft_strcpy(dest, s1);
	}
	return (dest);
}
