/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:18:36 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 15:01:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	get_operator_type(t_token *token)
{
	if (*(token->value) == '>' || *(token->value) == '<')
		token->type = T_REDIRECT;
	else if (*(token->value) == '|')
		token->type = T_PIPE;
	else
		token->type = T_UNSPEC_OP;
}

static void	get_digit_type(t_token *token)
{
	if (!ft_strchr(token->value, '.'))
		token->type = T_INT;
	else
		token->type = T_DOUBLE;
}

int	ft_compare_strings(char *str1, char *str2, size_t len2)
{
	size_t	len1;

	len1 = ft_strlen(str1);
	if (!ft_strncmp(str1, str2, len2) && len1 == len2)
		return (1);
	return (0);
}

static void	get_str_type(t_token *t)
{
	size_t	len;

	len = ft_strlen(t->value);
	if (len == 1)
		t->type = T_CHAR;
	else if (ft_compare_strings("echo", t->value, len)
		|| ft_compare_strings("cd", t->value, len)
		|| ft_compare_strings("pwd", t->value, len)
		|| ft_compare_strings("export", t->value, len)
		|| ft_compare_strings("unset", t->value, len)
		|| ft_compare_strings("env", t->value, len)
		|| ft_compare_strings("exit", t->value, len))
		t->type = T_KEYWORD;
	else
		t->type = T_STRING;
}

void	get_type(t_token *token, int type)
{
	if (!token->value)
		return ;
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
    <<: Used for heredoc to redirect multiple lines of input to a command,
	using a delimiter.
- unspec_op

PUNCTUATION
- quote
- d_quote
- dollar
- unspec_punc
 */
