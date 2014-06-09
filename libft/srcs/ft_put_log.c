/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 17:03:42 by shedelin          #+#    #+#             */
/*   Updated: 2014/04/30 17:04:45 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <libft.h>

void	ft_put_log(char *str)
{
	int		fd;

	fd = open("log.txt", O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
	ft_putendl_fd(str, fd);
	close(fd);
}
