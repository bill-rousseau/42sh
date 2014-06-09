/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:16:28 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 22:36:45 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i])
	{
		n--;
		if (n == 0)
			return (0);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
