/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:56:10 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/05 19:25:36 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			ft_newchar(long nb, int base)
{
	if (base <= 10)
		return (nb + '0');
	else if (base <= 36)
	{
		if (nb < 10)
			return (nb + '0');
		else
			return (nb + 'A' - 10);
	}
	return ('#');
}

int				ft_sign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int nb, int base)
{
	char		*s;
	int			len;
	int			sign;
	long		n;

	n = nb;
	if ((s = (char *)malloc((12) * sizeof(char))) == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	len = 10;
	if ((sign = ft_sign(n)))
		n *= -1;
	s[len + 1] = 0;
	while (n)
	{
		s[len--] = ft_newchar(n % base, base);
		n /= base;
	}
	if (sign)
		s[len] = '-';
	return (ft_memmove(s, s + len + !sign, ft_strlen(s + len + !sign) + 1));
}
