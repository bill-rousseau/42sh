/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 15:17:58 by shedelin          #+#    #+#             */
/*   Updated: 2014/04/30 15:18:01 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

int		ft_putchar_col(int c, int color, char *state, int fd)
{
	ft_putstr_fd("\033[", fd);
	ft_putstr_fd(state, fd);
	ft_putchar_fd(';', fd);
	ft_putnbr_fd(color, fd);
	ft_putchar_fd('m', fd);
	return (write(fd, &c, 1) + ft_putstr_fd("\033[0m", fd));
}
