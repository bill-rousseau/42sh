/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:09:32 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/01 19:04:23 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (size == 0)
		return (NULL);
	str = (void *)malloc(size * sizeof(*str));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
