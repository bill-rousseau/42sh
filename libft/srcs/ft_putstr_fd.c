/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:05:14 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/19 21:01:47 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr_fd(const char *s, int fd)
{
	if (s && fd != -1)
		return (write(fd, s, ft_strlen(s)));
	else if (!s)
		return (0);
	else
		return (-1);
}
