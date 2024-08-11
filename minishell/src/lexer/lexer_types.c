/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:18:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/11 13:54:31 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void get_operator_type(t_token *token)
{
    if (*(token->value) == '>' || *(token->value) == '<')
        token->type = REDIRECT;
    else if (*(token->value) == '|')
        token->type = PIPE;
    else
        token->type = UNSPEC_OP;
}

static void get_digit_type(t_token *token)
{
    if (!ft_strchr(token->value, '.'))
        token->type = INT;
    else
        token->type = DOUBLE;
}

static void get_str_type(t_token *token)
{
    size_t len;
    
    len = ft_strlen(token->value);
    if (len == 1)
        token->type = CHAR;
    else if ((!(ft_strncmp("echo", token->value, len)) && len == ft_strlen("echo"))
        || (!(ft_strncmp("cd", token->value, len)) && len == ft_strlen("cd"))
        || (!(ft_strncmp("pwd", token->value, len)) && len == ft_strlen("pwd"))
        || (!(ft_strncmp("export", token->value, len)) && len == ft_strlen("export"))
        || (!(ft_strncmp("unset", token->value, len)) && len == ft_strlen("unset"))
        || (!(ft_strncmp("env", token->value, len)) && len == ft_strlen("env"))
        || (!(ft_strncmp("exit", token->value, len)) && len == ft_strlen("exit")))
        token->type = KEYWORD;
    else
        token->type = STRING;
}

void    get_type(t_token *token, int type)
{
    if (type == 1)
        get_str_type(token);
    if (type == 2)
        get_digit_type(token);
    if (type == 3)
        get_operator_type(token);
}

/*CHECK QUOTED TYPE : 
- if is digit : check if num
- if is operator && ft_strlen < 2 : check if operator
- else : is str*/


/* ALPHA TYPES
- char
- keyword
    > echo
    > cd
    > pwd
    > export
    > unset
    > env
    > env
    > exit
- string

DIGIT TYPE
- double (float ?)
- int

OPERATOR
- redirect (dissociate w/ check_redirect later)
    >: Redirect cmd output to file + overwrite
    <: Redirect cmd input to come from a file
    >>: Redirects cmd output to file + append
    <<: Used for heredoc to redirect multiple lines of input to a command, using a delimiter.
- unspec_op

PUNCTUATION
- quote
- d_quote
- dollar
- unspec_punc
 */
