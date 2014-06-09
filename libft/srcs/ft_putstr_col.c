/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 15:18:16 by shedelin          #+#    #+#             */
/*   Updated: 2014/04/30 15:18:17 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

int		ft_putstr_col(char *str, int color, char *state, int fd)
{
	if (!str)
		return (0);
	ft_putstr_fd("\033[", fd);
	ft_putstr_fd(state, fd);
	ft_putchar_fd(';', fd);
	ft_putnbr_fd(color, fd);
	ft_putchar_fd('m', fd);
	return (write(fd, str, ft_strlen(str)) + ft_putstr_fd("\033[0m", fd) - 4);
}
