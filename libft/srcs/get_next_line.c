/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:16:34 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/11 20:33:00 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>

int			get_next_line(int const fd, char **line)
{
	static char		*str;
	int				size;

	if (str == NULL)
		str = ft_strnew(0);
	size = ft_gnl_read_buf(fd, &str);
	if (size == -1)
		return (-1);
	else if (size == 0 && *str == 0)
		return (0);
	else
		return (ft_gnl_copy_line(line, str, size));
}

int			ft_gnl_copy_line(char **line, char *str, int size)
{
	int			len;

	if (*line != NULL)
		ft_strdel(line);
	if (ft_strchr(str, '\n'))
	{
		*line = ft_strcdup(str, '\n');
		len = ft_strlen(*line);
		ft_memmove(str, str + (len + 1), (ft_strlen(str) - len));
	}
	else if (size == 0)
		*line = ft_strdup(str);
	return (1);
}

int			ft_gnl_read_buf(int fd, char **str)
{
	char		buf[BUFF_SIZE];
	char		*tmp;
	int			size;

	while (!(ft_strchr(*str, '\n')) && (size = read(fd, buf, BUFF_SIZE)) >= 1)
	{
		buf[size] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, buf);
		free (tmp);
	}
	return (size);
}
