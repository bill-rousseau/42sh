/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:01:51 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 21:17:59 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (n != 0)
	{
		dest[i] = src[j];
		i++;
		if (src[j] != '\0')
			j++;
		n--;
	}
	return (dest);
}
