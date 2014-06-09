/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:04:27 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/03 14:51:27 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;
	int		j;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	j = 0;
	if (size <= len_dest)
		return (size + len_src);
	while (i < size - 1 && dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}
