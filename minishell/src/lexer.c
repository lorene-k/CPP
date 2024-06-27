/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:04:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/27 19:22:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void     ft_getnonascii(t_token *token, char *line, int *i)
{
    int	j;

	j = 0;
	while (!ft_isascii(line[*i + j]))
		j++;
	token->value = ft_substr(line, *i, j);
	*i += j;
    token->type = NON_ASCII;
}

static void     ft_getspecchar(t_token *token, char *line, int *i)
{
    if (ft_isoperator(line[*i]))
    {
        get_value(token, line, i, 3);
        get_type(token, 3);
    }
    else if (ft_ispunctuation(line[*i]))
    {
        get_value(token, line, i, 4);
        get_type(token, 4);
    }
}

static void     ft_getconstant(t_token *token, char *line, int *i)
{
    if (ft_isalpha(line[*i]))
    {
        get_value(token, line, i, 1);
        get_type(token, 1);
    }
    else if (ft_isdigit(line[*i]))
    {
        get_value(token, line, i, 2);
        get_type(token, 2);
    }
}

void     lexer(t_data *data, t_token *token, char *line)
{
    int i;

    i = 0;
    token = NULL;
    data->token = token;
    while (line[i])
    {
        add_token(&token);
        if (!token)
            return ; //PROTECT MALLOCS
        while (ft_isspace(line[i]))
            i++;
        if (line[i] == '#') //HANDLE COMMENTS ??
            break ;
        if (ft_isalnum(line[i]))
            ft_getconstant(token, line, &i);
        if (ft_isspecchar(line[i]))
            ft_getspecchar(token, line, &i);
        if (!(ft_isascii(line[i]))) //CHECK NON ASCII CHARS
            ft_getnonascii(token, line, &i);
        printf("token value : %s - token type : %d\n", token->value, token->type); //TEST
    }
}


/* LEXER
    TYPES
    - constants (integers, doubles, characters, strings)
    - operators (arithmetic, logical, relational)
    - punctuation (commas, semicolons, braces)
    - keywords (reserved words with predefined meanings like if, while, return) */


// OPERATORS
// **
// &&
// ||
// !=
// =
// !
// +
// /
// %
// -
// < 
// >
// >>
// <<
// ^

// PUNCTUATION
// - not handled
// - quotes
// - double quotes
// - dollar
// - parentheses ?