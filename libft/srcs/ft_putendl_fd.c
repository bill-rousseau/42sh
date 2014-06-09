/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:47:08 by shedelin          #+#    #+#             */
/*   Updated: 2013/11/26 21:09:20 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = ft_strlen(s);
	write(fd, s, len);
	ft_putchar_fd('\n', fd);
}
