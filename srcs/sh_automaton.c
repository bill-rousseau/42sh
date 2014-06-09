/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_automaton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 22:16:50 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/13 22:16:51 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh.h"

int			sh_initauto(t_auto *autom, int size)
{
	autom->status = _wait;
	autom->i = 0;
	if (!(autom->buf = (char *)sh_malloc((size + 1) * sizeof(char))))
		return (0);
	ft_bzero(autom->buf, size);
	autom->l_lex = NULL;
	return (1);
}

int			sh_automaton(t_auto *autom, char c)
{
	static t_func	func[] =

	{
	sh_lex_wait,
	sh_lex_and,
	sh_lex_sep,
	sh_lex_or,
	sh_lex_right,
	sh_lex_pipe,
	sh_lex_left,
	sh_lex_word
	};
	if (!func[autom->status](autom, c))
	{
		sh_dellex(&autom->l_lex);
		return (0);
	}
	return (1);
}

int			sh_addtoken(t_auto *autom)
{
	t_lex	*new;

	if (!(new = sh_newlex(autom)))
	{
		autom->l_lex = NULL;
		return (0);
	}
	sh_lexadd(&autom->l_lex, new);
	autom->i = 0;
	ft_bzero(autom->buf, ft_strlen(autom->buf));
	return (1);
}
