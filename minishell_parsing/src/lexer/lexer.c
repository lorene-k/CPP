/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:04:02 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 14:07:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_getconstant(t_token *token, char *line, int *i)
{
	int	is_str;
	int	j;

	is_str = 0;
	j = *i;
	if (ft_isdigit(line[*i]) || ft_issign(line[*i]))
	{
		is_str = get_value(token, line, &j, 2);
		if (!is_str)
		{
			get_type(token, 2);
			*i = j;
			return ;
		}
	}
	get_value(token, line, &j, 1);
	get_type(token, 1);
	*i = j;
}

static void	ft_getspecchar(t_token *token, char *line, int *i, t_data *data)
{
	int	is_str;
	int	j;

	is_str = 0;
	j = *i;
	if (ft_solo_operator(line, *i) || ft_multi_operator(line, *i))
	{
		get_value(token, line, &j, 3);
		get_type(token, 3);
	}
	else if (ft_ispunctuation(line[*i]))
		is_str = get_punctuation(&token, data, &j);
	if (is_str || (!ft_ispunctuation(line[*i]) && !ft_solo_operator(line, *i)
			&& !ft_multi_operator(line, *i)))
		ft_getconstant(token, line, &j);
	*i = j;
}

t_token	*lexer(t_token *token, char *line, t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line))
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '#')
			break ;
		add_node(&token, 0, 0);
		if (!token)
		{
			print_error(MALLOC_ERR, NULL, 1, data);
			break ;
		}
		if (ft_isspecchar(line[i]))
			ft_getspecchar(token, line, &i, data);
		else if (ft_isalnum(line[i]) || ft_issign(line[i])
			|| !ft_isascii(line[i]))
			ft_getconstant(token, line, &i);
		// printf(" TOKEN TESTER : token %d value : %s\t type : %d\n\n", i, token->value, token->type); //TEST
	}
	token = get_first_node(token, 0, 0);
	return (token);
}

/* LEXER
    TYPES
    - constants (integers, doubles, characters, strings)
    - operators (arithmetic, logical, relational)
    - punctuation (commas, semicolons, braces)
    - keywords (reserved words with predefined meanings like if, while,
		return) */

// OPERATORS
// **
// &&
// ||
// != >> not handled in ft_getspecchar
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