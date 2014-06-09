/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:04:10 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 21:17:35 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (n != 0)
	{
		if (src[j] == '\0')
			n = 0;
		else
		{
			dest[i] = src[j];
			i++;
			j++;
			n--;
		}
	}
	dest[i] = '\0';
	return (dest);
}
