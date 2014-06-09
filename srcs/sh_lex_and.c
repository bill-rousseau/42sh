/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_and.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 15:44:46 by shedelin          #+#    #+#             */
/*   Updated: 2014/05/15 15:44:48 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh.h"

int		sh_lex_and(t_auto *autom, char c)
{
	if (autom->i == 1 && c != '&')
		return (sh_error_str(2, autom->buf));
	autom->buf[autom->i] = c;
	autom->i += 1;
	if (!sh_addtoken(autom))
		return (0);
	autom->status = _wait;
	return (1);
}

int		sh_lex_wait(t_auto *autom, char c)
{
	if (ft_iswhite(c))
		return (1);
	if (!c)
		autom->status = _end;
	else if (c == '&')
		autom->status = _and;
	else if (c == ';')
		autom->status = _sep;
	else if (c == '|')
		autom->status = _pipe;
	else if (c == '>')
		autom->status = _right;
	else if (c == '<')
		autom->status = _left;
	else
		autom->status = _word;
	autom->buf[autom->i] = c;
	autom->i += 1;
	return (1);
}

int		sh_lex_sep(t_auto *autom, char c)
{
	if (!sh_addtoken(autom))
		return (0);
	autom->status = _wait;
	return (sh_lex_wait(autom, c));
}

int		sh_lex_or(t_auto *autom, char c)
{
	if (!sh_addtoken(autom))
		return (0);
	autom->status = _wait;
	return (sh_lex_wait(autom, c));
}

int		sh_lex_right(t_auto *autom, char c)
{
	if (autom->i == 1 && c == '>')
	{
		autom->buf[autom->i] = c;
		autom->i += 1;
		if (!sh_addtoken(autom))
			return (0);
		autom->status = _wait;
		return (1);
	}
	if (!sh_addtoken(autom))
		return (0);
	autom->status = _wait;
	return (sh_lex_wait(autom, c));
}
