/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/10 00:20:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void    check_quoted_input(char *buf, int i, t_token **token)
{
    char    *tmp;

    tmp = NULL;
    if (buf[i + 1])
    {
        tmp = ft_substr(buf, i + 1, ft_strlen(buf) - i);
        lexer(*token, tmp);
        free(tmp);
    }
    free(buf);
}

static void    handle_unclosed_quote(char quote, t_token **token)
{
    char    *buf;
    char    *tmp;
    int     i;
    char    *expansion;

    buf = NULL;
    tmp = NULL;
    expansion = NULL;
    i = 0;
    buf = ft_strjoin_memory(readline("> "), ft_strdup("\n"));
    while (1)
    {
         // CHECK EXPANSION
        i = ft_strchr_index(buf, quote);
        if (i != -1 && ft_count_chars(buf, quote) % 2 != 0)
            break ;
        buf = ft_strjoin_memory(buf, readline("> "));
        buf = ft_strjoin_gnl(buf, "\n");
    }
    tmp = ft_substr(buf, 0, i);
    if (!expansion)
    {
        if ((*token)->value)
            (*token)->value = ft_strjoin_memory((*token)->value, tmp);
        else
            (*token)->value = tmp;
    }
    //check_quoted_type (token);
    check_quoted_input(buf, i, token);
}

static int  get_quoted_value(char *line, int i, int *j, t_token **token)
{
    int     expansion;

    expansion = 0;
    while (line[i + (*j)] && line[i + (*j)] != line[i])
    {
        if (line[i + (*j)] == '$'
            && (line[i + (*j) + 1] == '?' || ft_isalpha(line[i + (*j) + 1])))
        {
            if ((*j) != 1 && !expansion) //retrieve input before expansion
                (*token)->value = ft_substr(line, i + 1, (*j) - 1); // get first part of quoted str (before expansion)
            expansion = handle_expansion(token, line, i, j);
        }
        else
            (*j)++;
    }
    return (expansion);
}

static int  handle_double_quotes(char *line, int i, t_token **token)
{
    int     j;
    int     expansion;

    j = 1;
    expansion = get_quoted_value(line, i, &j, token);
    if (expansion && j != expansion + 1 && j != 1) // handle expansion in the middle of quoted str  (expansion at end of quoted str handled in expand)
        (*token)->value = ft_strjoin_memory((*token)->value, ft_substr(line, i + expansion + 1, j - expansion - 1));
    else if (!expansion && j != 1) // handle no expansion
        (*token)->value = ft_substr(line, i + 1, j - 1);
    if (!line[i + j]) //handle unclosed quote (check behavior if j == 1)
    {    
        (*token)->value = ft_strjoin_memory((*token)->value, ft_strdup("\n"));
        handle_unclosed_quote(line[i], token);
    }
    return (j);
}

static int  handle_single_quotes(char *line, int i, char quote, t_token **token)
{
    int j;

    j = 1;
    while (line[i + j] && line[i + j] != quote)
        j++;
    if (j != 1)
        (*token)->value = ft_substr(line, i + 1, j - 1);
    if (!line[i + j])
        handle_unclosed_quote(quote, token); //protect token if j == 1 >> NOT WORKING
    return (j);
}

static int  handle_quotes(t_token **token, char *line, int i, char quote)
{
    int		j;

    j = 1;
    if (quote == '\"')
        j = handle_double_quotes(line, i, token);
    else
        j = handle_single_quotes(line, i, quote, token);
    //check_quoted_type (token);
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