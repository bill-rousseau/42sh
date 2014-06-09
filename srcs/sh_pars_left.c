/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pars_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 14:45:47 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 14:45:49 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh.h"

int			sh_pars_left(t_tree *tree)
{
	t_lex	*tmp;

	if (!tree)
		return (1);
	tmp = tree->list;
	while (tmp && tmp->type != _left)
		tmp = tmp->next;
	if (!tmp)
		return (sh_pars_cmd(tree));
	if (sh_lexlen(tree->list) < 3)
		return (sh_error_str(1, PARS_LEFT_USAGE));
	if (tmp == tree->list && !(sh_pars_left_first(tree, tmp)))
		return (0);
	else if (tmp != tree->list && !sh_pars_left_mid(tree, tmp))
		return (0);
	tree->left->type = _word;
	tree->right->type = _word;
	if (!sh_pars_left(tree->right))
		return (0);
	return (1);
}

int			sh_pars_cmd(t_tree *tree)
{
	if (!tree)
		return (1);
	tree->type = _word;
	return (1);
}

int			sh_pars_left_first(t_tree *tree, t_lex *tmp)
{
	tree->list = tmp;
	if (tmp->next->type != _word || tmp->next->next->type != _word)
		return (sh_error_str(1, PARS_LEFT_USAGE));
	if (!(tree->left = sh_newtree(tmp->next)))
		return (0);
	if (!(tree->right = sh_newtree(tmp->next->next)))
		return (0);
	tree->type = _left;
	tmp->next->next = NULL;
	tmp->next = NULL;
	return (1);
}

int			sh_pars_left_mid(t_tree *tree, t_lex *tmp)
{
	if (tmp->next->type != _word)
		return (sh_error_str(1, PARS_LEFT_USAGE));
	if (!sh_addtree(tree, tmp, _left))
		return (0);
	return (1);
}
