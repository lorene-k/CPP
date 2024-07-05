/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:04:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/05 18:24:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void     ft_getnonascii(t_token *token, char *line, int *i)
{
    int	j;

	j = 0;
	while (!ft_isascii(line[*i + j]))
		j++;
	token->value = ft_substr(line, *i, j); // j - 1 <<<<
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
        get_punctuation(&token, line, i);
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

t_token     *lexer(t_token *token, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        while (ft_isspace(line[i]))
            i++;
        if (line[i] == '#') //HANDLE COMMENTS after quotes !!!
            break ;
        add_token(&token);
        if (!token)
            return (NULL); //PROTECT MALLOCS
        if (ft_isspecchar(line[i]))
            ft_getspecchar(token, line, &i); //else if or if ?
        else if (ft_isalnum(line[i]))
            ft_getconstant(token, line, &i);
        else if (!(ft_isascii(line[i]))) //CHECK NON ASCII CHARS
            ft_getnonascii(token, line, &i);
        // printf(" TOKEN TESTER : token %d value : %s\t type : %d\n\n", i, token->value, token->type); //TEST
    }
    token = get_first(token);
    return (token);
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
// - expansion : dollar
// - parentheses ?