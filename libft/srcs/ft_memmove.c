/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:42:22 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 19:18:32 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*s3;

	s3 = (char *)malloc(n * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s2, n);
	ft_memcpy(s1, s3, n);
	free(s3);
	return (s1);
}
