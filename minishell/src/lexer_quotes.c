/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/16 22:19:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int  get_quoted_value(char *line, int i, int *j, t_token **token)
{
    int     expansion;

    expansion = 0;
    while (line[i + (*j)] && (line[i + (*j)] != line[i]))
    {
        if (line[i + (*j)] == '$'
            && (line[i + (*j) + 1] == '?' || ft_isalpha(line[i + (*j) + 1])))
        {
            if ((*j) != 1 && !expansion) //retrieve input before expansion
                (*token)->value = ft_substr(line, i + 1, (*j) - 1); // get first part of quoted str (before expansion)
            else if ((*j) != 1 && expansion)
                (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(line, expansion + 1, (*j) - expansion - 1));
            expansion = handle_expansion(token, line, i, j);
        }
        else
            (*j)++;
    }
    return (expansion);
}

static int  handle_double_quotes(char *line, int i, t_token **token, int *unclosed_quote)
{
    int     j;
    int     expansion;

    j = 1;
    expansion = get_quoted_value(line, i, &j, token);
    if (expansion && j != expansion + 1 && j != 1) // handle expansion in the middle of quoted str (expansion at end of quoted str handled in expand)
        (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(line, i + expansion + 1, j - expansion - 1));
    else if (!expansion && j != 1) // handle no expansion
        (*token)->value = ft_substr(line, i + 1, j - 1);
    if (!line[i + j]) //handle unclosed quote (check behavior if j == 1)
    {
        *unclosed_quote += 1;
        handle_unclosed_quote(line[i], token);
    }
    return (j);
}

static int  handle_single_quotes(char *line, int i, t_token **token, int *unclosed_quote)
{
    int j;

    j = 1;
    while (line[i + j] && line[i + j] != line[i])
        j++;
    if (j != 1)
        (*token)->value = ft_substr(line, i + 1, j - 1);
    if (!line[i + j])
    {
        *unclosed_quote += 1;
        handle_unclosed_quote(line[i], token);
    }
    return (j);
}

static int  handle_quotes(t_token **token, char *line, int i, char quote)
{
    int		j;
    int    unclosed_quote;

    j = 1;
    unclosed_quote = 0;
    if (line[i] == line[i + 1])
        return (2);
    if (quote == '\"')
        j = handle_double_quotes(line, i, token, &unclosed_quote);
    else
        j = handle_single_quotes(line, i, token, &unclosed_quote);
    if (!unclosed_quote)
        check_type(token);
    return (j + 1);
}

int	get_punctuation(t_token **token, char *line, int *i)
{
    int j;

    j = 0;
	if (line[*i] == '\'' || line [*i] == '\"')
		*i += handle_quotes(token, line, *i, line[*i]);
	else if (line[*i] == '$'
        && (line[*i + 1] == '?' || ft_isalpha(line[*i + 1])))
		*i += handle_expansion(token, line, *i, &j) + 1;
	else if (!line[*i + 1] || ft_isspace(line[*i + 1]))
	{
		(*token)->value = ft_substr(line, *i, 1);
        (*token)->type = UNSPEC_PUNC;
		*i += 1;
	}
    else if (line[*i + 1] && !ft_isspace(line[*i + 1]))
        return (1);
    return (0);
}
