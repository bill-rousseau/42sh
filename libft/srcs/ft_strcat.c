/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:02:14 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/04 12:44:29 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	ft_strcpy(dest + i, src);
	return (dest);
}
