/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:17:05 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 16:30:26 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	if (!(s == NULL || f == NULL))
	{
		i = ft_strlen(s);
		dest = (char *)malloc(i + 1 * sizeof(*s));
		i = 0;
		while (s[i] != '\0')
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
