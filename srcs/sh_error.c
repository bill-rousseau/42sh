/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/08 19:03:20 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/08 19:03:21 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

void		sh_error_exit(int error, char *str)
{
	if (str)
		ft_putstr_col(str, RED, BOLD, 2);
	if (error == 1)
		ft_putendl_col("A Malloc fail.", RED, NORMAL, 2);
	if (error == 2)
		ft_putendl_col("A pipe fail.", RED, NORMAL, 2);
	exit(error);
}

int			sh_error(int error, char *str)
{
	if (str)
		ft_putstr_col(str, GREEN, BOLD, 2);
	if (error == 1)
		ft_putendl_col("Error : Environement not found.", RED, NORMAL, 2);
	else if (error == 2)
		ft_putendl_col(": No termcap available.", RED, NORMAL, 2);
	else if (error == 3)
		ft_putendl_col("A fork fail.", RED, NORMAL, 2);
	else if (error == 4)
		ft_putendl_col(" : File not found or access denied.", RED, NORMAL, 2);
	else if (error == 5)
		ft_putendl_col("Multi < not allowed", RED, NORMAL, 2);
	else if (error == 6)
		ft_putendl_col(" : Command not found.", RED, NORMAL, 2);
	else if (error == 7)
		ft_putendl_col("Too many arguments.", RED, NORMAL, 2);
	else if (error == 8)
		ft_putendl_col("No such files or directory.", RED, NORMAL, 2);
	else if (error == 9)
		ft_putendl_col("usage: setenv NAME VALUE.", RED, NORMAL, 2);
	else if (error == 10)
		ft_putendl_col(" : Not found.", RED, NORMAL, 2);
	return (error);
}

int			sh_error_str(int error, char *str)
{
	if (error == 1)
		ft_putstr_col("Pars error : ", GREEN, NORMAL, 2);
	else if (error == 2)
		ft_putstr_col("Forbidden operator : ", GREEN, NORMAL, 2);
	else if (error == 3)
		ft_putstr_col("Error : Couldn't open file : ", GREEN, NORMAL, 2);
	else if (error == 4)
		ft_putendl_col("usage: unsetenv NAME1 [NAME2, ...].", RED, NORMAL, 2);
	if (str)
		ft_putendl_col(str, RED, BOLD, 2);
	return (0);
}
