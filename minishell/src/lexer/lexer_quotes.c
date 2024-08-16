/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 15:02:01 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_quoted_value(t_data *d, int i, int *j, t_token **token)
{
	int	expansion;

	expansion = 0;
	while (d->line[i + (*j)] && (d->line[i + (*j)] != d->line[i]))
	{
		if (d->line[i + (*j)] == '$' && (d->line[i + (*j) + 1] == '?'
				|| ft_isalpha(d->line[i + (*j) + 1])))
		{
			if ((*j) != 1 && !expansion)
				(*token)->value = ft_substr(d->line, i + 1, (*j) - 1);
			else if ((*j) != 1 && expansion)
				(*token)->value = ft_strjoin_memory((*token)->value,
						ft_substr(d->line, expansion + 1, (*j) - expansion - 1));
			expansion = handle_expansion(token, d, i, j);
		}
		else
			(*j)++;
	}
	return (expansion);
}

static int	handle_double_quotes(t_data *d, int i, t_token **token, int *unclosed_quote)
{
	int	j;
	int	expansion;

	j = 1;
	expansion = get_quoted_value(d, i, &j, token);
	if (expansion && j != expansion + 1 && j != 1)
		(*token)->value = ft_strjoin_memory((*token)->value, ft_substr(d->line, i + expansion + 1, j - expansion - 1));
	else if (!expansion && j != 1)
		(*token)->value = ft_substr(d->line, i + 1, j - 1);
	if (!(d->line[i + j]))
	{
		*unclosed_quote += 1;
		handle_unclosed_quote(d->line[i], token, d);
	}
	return (j);
}

static int	handle_single_quotes(t_data *d, int i, t_token **token, int *unclosed_quote)
{
	int	j;

	j = 1;
	while (d->line[i + j] && d->line[i + j] != d->line[i])
		j++;
	if (j != 1)
		(*token)->value = ft_substr(d->line, i + 1, j - 1);
	if (!d->line[i + j])
	{
		*unclosed_quote += 1;
		handle_unclosed_quote(d->line[i], token, d);
	}
	return (j);
}

static int	handle_quotes(t_token **token, t_data *d, int i, char quote)
{
	int	j;
	int	unclosed_quote;

	j = 1;
	unclosed_quote = 0;
	if (d->line[i] == d->line[i + 1])
		return (2);
	if (quote == '\"')
		j = handle_double_quotes(d, i, token, &unclosed_quote);
	else
		j = handle_single_quotes(d, i, token, &unclosed_quote);
	if (!unclosed_quote)
		check_type(token);
	return (j + 1);
}

int	get_punctuation(t_token **token, t_data *d, int *i)
{
	int	j;

	j = 0;
	if (d->line[*i] == '\'' || d->line[*i] == '\"')
		*i += handle_quotes(token, d, *i, d->line[*i]);
	else if (d->line[*i] == '$' && (d->line[*i + 1] == '?' || ft_isalpha(d->line[*i + 1])))
		*i += handle_expansion(token, d, *i, &j) + 1;
	else if (!d->line[*i + 1] || ft_isspace(d->line[*i + 1]))
	{
		(*token)->value = ft_substr(d->line, *i, 1);
		(*token)->type = T_UNSPEC_PUNC;
		*i += 1;
	}
	else if (d->line[*i + 1] && !ft_isspace(d->line[*i + 1]))
		return (1);
	return (0);
}
