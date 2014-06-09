/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pars_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 23:01:40 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/13 23:01:41 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh.h"

int		sh_pars_and(t_tree *tree)
{
	t_lex	*tmp;

	if (!tree)
		return (1);
	tmp = tree->list;
	while (tmp && tmp->type != _and)
		tmp = tmp->next;
	if (!tmp)
		return (sh_pars_sep(tree));
	if (!tmp->prev || tmp->prev->type != _word)
		return (sh_error_str(1, PARS_AND_NOCMD));
	if (!tmp->next || !(tmp->next->type == _word || tmp->next->type == _left))
		return (sh_error_str(1, PARS_AND_NOCMD));
	if (!sh_addtree(tree, tmp, _and))
		return (0);
	if (!sh_pars_sep(tree->left))
		return (0);
	if (!sh_pars_and(tree->right))
		return (0);
	return (1);
}

int		sh_pars_sep(t_tree *tree)
{
	t_lex	*tmp;

	if (!tree)
		return (1);
	tmp = tree->list;
	while (tmp && tmp->type != _sep)
		tmp = tmp->next;
	if (!tmp)
		return (sh_pars_or(tree));
	if (!sh_addtree(tree, tmp, _sep))
		return (0);
	if (tree->left && tree->left->list->type == _sep)
	{
		free(tree->left);
		tree->left = NULL;
	}
	if (!sh_pars_or(tree->left))
		return (0);
	if (!sh_pars_sep(tree->right))
		return (0);
	return (1);
}

int		sh_pars_or(t_tree *tree)
{
	t_lex	*tmp;

	if (!tree)
		return (1);
	tmp = tree->list;
	while (tmp && tmp->type != _or)
		tmp = tmp->next;
	if (!tmp)
		return (sh_pars_right(tree));
	if (!tmp->prev || tmp->prev->type != _word)
		return (sh_error_str(1, PARS_OR_NOCMD));
	if (!tmp->next || tmp->next->type != _word)
		return (sh_error_str(1, PARS_OR_NOCMD));
	if (!sh_addtree(tree, tmp, _or))
		return (0);
	if (!sh_pars_right(tree->left))
		return (0);
	if (!sh_pars_or(tree->right))
		return (0);
	return (1);
}

int		sh_pars_right(t_tree *tree)
{
	t_lex	*tmp;

	if (!tree)
		return (1);
	tmp = tree->list;
	while (tmp && tmp->type != _right)
		tmp = tmp->next;
	if (!tmp)
		return (sh_pars_pipe(tree));
	if (!tmp->prev || tmp->prev->type != _word)
		return (sh_error_str(1, PARS_RIGHT_NOCMD));
	if (!tmp->next || tmp->next->type != _word)
		return (sh_error_str(1, PARS_RIGHT_NOFILE));
	if (!sh_addtree(tree, tmp, _right))
		return (0);
	if (!sh_pars_pipe(tree->left))
		return (0);
	if (!sh_pars_right(tree->right))
		return (0);
	return (1);
}

int		sh_pars_pipe(t_tree *tree)
{
	t_lex	*tmp;

	if (!tree)
		return (1);
	tmp = tree->list;
	while (tmp && tmp->type != _pipe)
		tmp = tmp->next;
	if (!tmp)
		return (sh_pars_left(tree));
	if (!tmp->prev || tmp->prev->type != _word)
		return (sh_error_str(1, PARS_PIPE_NOCMD));
	if (!tmp->next || tmp->next->type != _word)
		return (sh_error_str(1, PARS_PIPE_NOCMD));
	if (!sh_addtree(tree, tmp, _pipe))
		return (0);
	if (!sh_pars_left(tree->left))
		return (0);
	if (!sh_pars_pipe(tree->right))
		return (0);
	return (1);
}
