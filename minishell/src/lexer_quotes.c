/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/05 18:30:55 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char    *handle_unclosed_quote() //TEST - TO DO //what happens to line here ?
{
    printf("UNCLOSED QUOTE\n");
    return ("UNCLOSED_QUOTE_TEST"); //use malloc here
}

static char    *get_quoted_value(char *line, int i, int *j, int expansion)
{
    char    *value;

    value = NULL;
    if (!line[i + (*j)])
        value = handle_unclosed_quote(); //DO THIS >> return char *value;
    else if ((*j) == 1) // handle empty str
    {
        (*j) += 1;
        return (NULL);
    }
    if (!expansion) // handle no expansion
        value = ft_substr(line, i + 1, (*j) - 1);
    return (value);
}

static int  handle_double_quotes(char *line, int i, char quote, t_token **token)
{
    int     j;
    int     expansion;
    char    *end_str;

    j = 1;
    expansion = 0;
    end_str = NULL;
    while (line[i + j] && line[i + j] != quote)
    {
        if (line[i + j] == '$'
            && (line[i + j + 1] == '?' || ft_isalpha(line[i + j + 1]))) //CHECK BEHAVIOR IF MULTIPLE EXPANSIONS
        {
            if (j != 1 && !expansion)
                (*token)->value = ft_substr(line, i + 1, j - 1); // get first part of quoted str (before expansion)
            expansion = handle_expansion(token, line, i, &j);
        }
        else
            j++;
    }
    if (expansion && j != expansion + 1) // handle expansion in the middle of quoted str
        (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(line, i + expansion + 1, j - expansion - 1));
    else if (!expansion)// handle no expansion (expansion at end of quoted str handled in expand)
        (*token)->value = get_quoted_value(line, i, &j, expansion);
    return (j);
}

static int  handle_single_quotes(char *line, int i, char quote, t_token **token)
{
    int j;

    j = 1;
    while (line[i + j] && line[i + j] != quote)
        j++;
    if (!line[i + j])
        return (handle_unclosed_quote(), j); //DO THIS
    else if (j == 1)
        return (j + 1);
    (*token)->value = ft_substr(line, i + 1, j - 1);
    return (j);
}

static int  handle_quotes(t_token **token, char *line, int i, char quote) //check spec cases + quotes within quotes
{
    int		j;
    int     quote_n;

    j = 1;
    quote_n = 1;
    if (quote == '\"')
        j = handle_double_quotes(line, i, quote, token);
    else
        j = handle_single_quotes(line, i, quote, token);
    //check_type (token, quote);
    return (j + 1);
}

void	get_punctuation(t_token **token, char *line, int *i)
{
    int j;

    j = 0;
	if (line[*i] == '\'' || line [*i] == '\"')
		*i += handle_quotes(token, line, *i, line[*i]);
	else if (line[*i] == '$'
        && (line[*i + 1] == '?' || ft_isalpha(line[*i + 1])))
		*i += handle_expansion(token, line, *i, &j) + 1;
	else
	{
		(*token)->value = ft_substr(line, *i, 1);
        (*token)->type = UNSPEC_PUNC;
		*i += 1;
	}
}
/*
SINGLE QUOTES 
- tokenize anything within quotes
- if quotes in single quotes, don't write them BUT write double quotes

DOUBLE QUOTES
- Variable Expansion: Variables within double quotes are expanded.
- if double quotes in double quotes, don't write them BUT write single quotes

NO CLOSING QUOTE (odd number of quotes)
- give back prompt w/ readline(">") and wait for new input w/ closing quote
(- tokenize each newline too)
*/