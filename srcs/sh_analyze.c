/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_analyze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 21:17:51 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/13 21:17:53 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

t_tree		*sh_analyze(char *line)
{
	t_tree	*tree;
	t_auto	autom;
	int		i;
	int		size;

	size = ft_strlen(line);
	if (!sh_initauto(&autom, size))
		return (0);
	i = -1;
	while (++i <= size)
	{
		if (!sh_automaton(&autom, line[i]))
		{
			ft_strdel(&(autom.buf));
			return (0);
		}
	}
	ft_strdel(&(autom.buf));
	tree = sh_pars(autom.l_lex);
	return (tree);
}

t_tree		*sh_pars(t_lex *lex)
{
	t_tree	*tree;

	if (!(tree = sh_newtree(lex)))
		return (NULL);
	if (!sh_pars_and(tree))
	{
		sh_deltree(&tree);
		return (NULL);
	}
	return (tree);
}
