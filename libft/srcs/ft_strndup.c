/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 18:18:26 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/31 18:18:30 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char		*ft_strndup(char *src, int i)
{
	int		j;
	char	*dest;

	j = 0;
	dest = (char *)malloc((i + 1) * sizeof(char));
	while (i >= 0)
	{
		dest[j] = src[j];
		j++;
		i--;
	}
	dest[j] = '\0';
	return (dest);
}
