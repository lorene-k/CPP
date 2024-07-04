/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_specials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:02:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/04 17:50:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

//get_exit_code(t_token **token)
//expand_value(t_token **token, char *to_expand) //don't forget to free(to_expand)

static int 	handle_expansion(t_token **token, char *line, int i, int *j) // expand variables THEN tokenize expansion, except if within d_quotes (then, continue to tokenize until last quote)
{
    (*token)->value = ft_substr(line, i, j); //j - 1?
    if (line[i + (*j) + 1] == '?')
    { 
        // get_exit_code(token); //get exit code & malloc str to contain value, then copy it to token value
        j++;
    }
	else if (ft_isalpha(line[i + 1]))
	{
        while (ft_isalnum(line[i + (*j)]))
            j++;
        // expand_value(token, ft_substr(line, i + 1, j)) //same mechanism as get_exit_code
	    return (j);
    }
    return (1);
}

static int handle_unclosed_quote() //TEST - TO DO 
{
    printf("UNCLOSED QUOTE\n");
    return (1);
}

static int  handle_double_quotes(char *line, int i, char quote, t_token **token)
{
    int j;
    int expansion;

    j = 1;
    expansion = 0;
    while (line[i + j] && line[i + j] != quote)
    {
        if (line[i + j] == '$'
            && (line[i + j + 1] == '?' || ft_isalpha(line[i + j + 1])))
            expansion = handle_expansion(token, line, i, &j);
        else
            j++;
    }
    if (!line[i + j])
        return (handle_unclosed_quote()); //DO THIS
    else if (j == 1)
        return (j + 1);
    if (!expansion)
        (*token)->value = ft_substr(line, i + 1, j - 1);
    // else
    //     add rest of line to token
    return (j);
}

static int  handle_single_quotes(char *line, int i, char quote, t_token **token)
{
    int j;

    j = 1;
    while (line[i + j] && line[i + j] != quote)
        j++;
    if (!line[i + j])
        return (handle_unclosed_quote()); //DO THIS
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
        j = handle_double_quotes(line, i, quote, token); // TEST
    else
        j = handle_single_quotes(line, i, quote, token); //HANDLE TYPE
    //check_type (token, quote);
    return (j + 1);
}

void	get_punctuation(t_token *token, char *line, int *i)
{
	int	j;

	j = 0;
	if (line[*i] == '\'' || line [*i] == '\"')
		*i += handle_quotes(&token, line, *i, line[*i]);
	else if (line[*i] == '$'
        && (line[*i + 1] == '?' || ft_isalpha(line[*i + 1])))
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