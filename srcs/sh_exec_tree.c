/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 18:40:16 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 18:40:17 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh.h"

void		sh_exec_tree(t_tree *tree)
{
	if (!tree)
		return ;
	else if (tree->type == _sep)
	{
		sh_exec_tree(tree->left);
		sh_exec_tree(tree->right);
	}
	else if (tree->type == _pipe)
		sh_exec_pipe(tree);
	else if (tree->type == _and)
		sh_exec_and(tree);
	else if (tree->type == _or)
		sh_exec_or(tree);
	else if (tree->type == _left)
		sh_exec_left(tree);
	else if (tree->type == _right)
		sh_exec_right(tree);
	else if (tree->type == _word)
		sh_exec_word(tree);
}
