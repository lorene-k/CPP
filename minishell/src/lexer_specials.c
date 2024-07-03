/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_specials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/03 23:53:04 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

// static int  check_quotes(t_token **token, char *line, int i, char quote)
// {
//     int     s_quote;
//     int     d_quote;
    
//     if (quote == '\"')
//         d_quote = 1;
//     else
//         d_quote = 0;
//     s_quote = !d_quote;
// }

static int  handle_double_quotes(t_token **token, char *line, int i, char d_quote)
{
    int j;

    j = 1;
    while (line[i + j] && line[i + j] != d_quote) // HANDLE QUOTES WITHIN QUOTES
    {
        if (line[i + j] == '$'
            && (line[i + j + 1] == '?' || ft_isalpha(line[i + j + 1])))
            j += handle_expansion(token, line, i + j); //check this
        else
            j++;
    }
    return (j);
}

static int  handle_single_quotes(t_token **token, char *line, int i, char s_quote)
{
    int j;

    j = 1;
    while (line[i + j] && line[i + j] != s_quote) // HANDLE QUOTES WITHIN QUOTES
        j++;
    return (j);      
}

static int  handle_quotes(t_token **token, char *line, int i, char quote) //check spec cases + quotes within quotes
{
    int		j;
    int     s_quote;
    int     d_quote;

    j = 1;
    if (quote == '\"')
        j = handle_double_quotes(token, line, i, quote);
    else
        j = handle_single_quotes(token, line, i, quote);
    (*token)->value = ft_substr(line, i, j);
    //check_type (digit, keyword, else)
    return (j + 1);
}

static int 	handle_expansion(t_token **token, char *line, int i)
{
    int j;

    j = 0;
    if (line[i] == '?')
	{	
        (*token)->value = ft_substr(line, i, 2);
        (*token)->type = EXIT_EXPANSION;
	    return (2);
    }
	else if (ft_isalpha(line[i]))
	{
        while (ft_isalnum(line[i + j]))
            j++;
        (*token)->value = ft_substr(line, i, j);
        (*token)->type = VAR_EXPANSION;
	    return (j);
    }
}

void	get_punctuation(t_token *token, char *line, int *i)
{
	int	j;

	j = 0;
	if (line[*i] == '\'' || line [*i] == '\"')
		*i += handle_quotes(&token, line, *i, line[*i]);
	else if (line[*i] == '$' && line[*i + 1] == '?'
        || ft_isalpha(line[*i + 1]))
		*i += handle_expansion(&token, line, *i);
	else
	{
		token->value = ft_substr(line, *i, 1);
        token->type = UNSPEC_PUNC;
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