/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 17:50:30 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 17:50:32 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh.h"

int		sh_lex_left(t_auto *autom, char c)
{
	if (!sh_addtoken(autom))
		return (0);
	autom->status = _wait;
	return (sh_lex_wait(autom, c));
}

int		sh_lex_word(t_auto *autom, char c)
{
	if (c == '&' || c == ';' || c == '|' || c == '>' || !c || ft_iswhite(c))
	{
		if (!sh_addtoken(autom))
			return (0);
		autom->status = _wait;
		return (sh_lex_wait(autom, c));
	}
	autom->buf[autom->i] = c;
	autom->i += 1;
	autom->buf[autom->i] = '\0';
	return (1);
}

int		sh_lex_pipe(t_auto *autom, char c)
{
	if (autom->i == 1 && c == '|')
	{
		autom->buf[autom->i] = c;
		autom->i += 1;
		autom->status = _or;
		return (1);
	}
	if (!sh_addtoken(autom))
		return (0);
	autom->status = _wait;
	return (sh_lex_wait(autom, c));
}
