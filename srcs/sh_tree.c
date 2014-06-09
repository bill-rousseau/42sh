/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:38:13 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/13 22:38:15 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh.h"

t_tree		*sh_newtree(t_lex *l_lex)
{
	t_tree	*new;

	if (!(new = (t_tree *)malloc(sizeof(t_tree))))
		return (0);
	new->list = NULL;
	new->left = NULL;
	new->right = NULL;
	new->type = 0;
	if (l_lex)
		new->list = l_lex;
	return (new);
}

void		sh_deltree(t_tree **tree)
{
	if (!*tree)
		return ;
	sh_dellex(&(*tree)->list);
	sh_deltree(&(*tree)->left);
	sh_deltree(&(*tree)->right);
	free(*tree);
	*tree = NULL;
}

int			sh_addtree(t_tree *tree, t_lex *tmp, int type)
{
	t_tree		*new;

	if (!(new = sh_newtree(tree->list)))
		return (0);
	tree->left = new;
	new = NULL;
	if (tmp->prev)
		tmp->prev->next = NULL;
	if (tmp->next)
	{
		if (!(new = sh_newtree(tmp->next)))
			return (0);
		tmp->next = NULL;
	}
	tree->right = new;
	tree->type = type;
	tree->list = tmp;
	return (1);
}
