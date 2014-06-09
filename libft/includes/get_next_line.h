/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <shedelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:53:59 by shedelin          #+#    #+#             */
/*   Updated: 2013/12/02 19:06:35 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4096

int		get_next_line(int const fd, char **line);
int		ft_gnl_copy_line(char **line, char *str, int size);
int		ft_gnl_read_buf(int fd, char **str);

#endif
