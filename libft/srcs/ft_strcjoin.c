/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 15:07:24 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/28 15:07:27 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strcjoin(char *s1, char *s2, char c)
{
	char	*sout;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	sout = (char *)malloc(lens1 + lens2 + 2);
	ft_strcpy(sout, s1);
	sout[lens1] = c;
	ft_strcpy(sout + lens1 + 1, s2);
	sout[lens1 + lens2 + 1] = 0;
	return (sout);
}
