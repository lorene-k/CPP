/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:03:44 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/28 11:45:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	get_operator_value(t_token *token, char *line, int *i)
{
	int	j;

	j = 0;
	check_operator(line, *i, &j);
	token->value = ft_substr(line, *i, j);
	*i += j;
}

static int	get_digit_value(t_token *token, char *line, int *i)
{
	int	j;

	j = 0;
	if (check_digit(line, *i, &j))
		return (1);
	token->value = ft_substr(line, *i, j);
	*i += j;
	return (0);
}

static void	get_str_value(t_token *token, char *line, int *i)
{
	int	j;

	j = 0;
	while (line[*i + j] && !ft_isspace(line[*i + j]) && line[*i + j] != '\''
		&& line[*i + j] != '\"')
		j++;
	token->value = ft_substr(line, *i, j);
	*i += j;
}

int	get_value(t_token *token, char *line, int *i, int type)
{
	if (type == 1)
		get_str_value(token, line, i);
	if (type == 2)
		return (get_digit_value(token, line, i));
	if (type == 3)
		get_operator_value(token, line, i);
	return (0);
}
