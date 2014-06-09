/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:59:41 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 20:38:57 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		return (write(fd, &c, 1));
	return (-1);
}
