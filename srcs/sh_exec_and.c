/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 20:53:55 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 20:53:56 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh.h"

void		sh_exec_and(t_tree *tree)
{
	sh_exec_tree(tree->left);
	if (g_last_return == 0)
		sh_exec_tree(tree->right);
}

void		sh_exec_or(t_tree *tree)
{
	sh_exec_tree(tree->left);
	if (g_last_return)
		sh_exec_tree(tree->right);
}
