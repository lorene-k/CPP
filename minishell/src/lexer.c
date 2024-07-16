/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:04:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/16 21:59:36 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void     ft_getconstant(t_token *token, char *line, int *i)
{
    int is_str;

    is_str = 0;
    if (ft_isdigit(line[*i]) || ft_issign(line[*i]))
    {
        is_str = get_value(token, line, i, 2);
        if (!is_str)
        {   
            get_type(token, 2);
            return ;
        }
    }
    get_value(token, line, i, 1);
    get_type(token, 1);
}

static void     ft_getspecchar(t_token *token, char *line, int *i)
{
    int is_str;
    
    is_str = 0;
    if (ft_isoperator(line[*i]) && (line[*i] == line[*i + 1]
        || ft_isspace(line[*i + 1]) || !line[*i + 1])) //doesn't consider =!
    {
        get_value(token, line, i, 3);
        get_type(token, 3);
    }
    else if (ft_ispunctuation(line[*i]))
        is_str = get_punctuation(&token, line, i);
    if (is_str || !ft_ispunctuation(line[*i]))
        ft_getconstant(token, line, i);
}

t_token     *lexer(t_token *token, char *line)
{
    int i;  

    i = 0;
    while (i < (int)ft_strlen(line))
    {
        while (ft_isspace(line[i]))
            i++;
        if (line[i] == '#')
            break ;
        add_token(&token);
        if (!token)
            return (NULL);
        if (ft_isspecchar(line[i])) // OR if (!ft_isalnum(line[i]))
            ft_getspecchar(token, line, &i);
        else if (ft_isalnum(line[i]) || ft_issign(line[i])
            || !ft_isascii(line[i])) //LOGIC PB? 
            ft_getconstant(token, line, &i);
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