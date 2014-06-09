/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:51:58 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/25 16:53:09 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup(s1));
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}
