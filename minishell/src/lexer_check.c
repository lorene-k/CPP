/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:12:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/16 13:08:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_quotes(char *line, int start, int k)
{
	char	*pre_line;

	if (!line[start + k] || ft_isspace(line[start + k]))
		return (0);
	pre_line = ft_substr(line, 0, start);
	if (line[start + k] == '\'' || line[start + k] == '\"')
	{
		if (ft_count_chars(pre_line, line[start + k]) % 2 == 0)
		{
			free(pre_line);
			return (1);
		}
		free(pre_line);
		return (0);
	}
	free(pre_line);
	return (1);
}

//CHECK IF IS OPERATOR + GET OPERATOR VALUE
int check_operator(char *line, int i, int *j)
{
	if ((!line[i + 2] || ft_isspace(line[i + 2]))
		&& ((line[i] == '!' && line[i + 1] == '=') || ((line[i] == line[i + 1])
		&& (line[i] == '*' || line[i] == '&' || line[i] == '|'
		|| line[i] == '>' || line[i] == '<'))))
	{
		(*j) += 2;
		return (0);
	}
	else if (ft_isoperator(line[i]) && (!line[i + 1] || ft_isspace(line[i + 1])))
	{	
		(*j) += 1;
		return (0);
	}
	return (1);
}

//CHECK IF IS DIGIT + GET DIGIT VALUE
int check_digit(char *line, int i, int *j)
{
	if (!ft_isdigit(line[i]) && !ft_issign(line[i]))
		return (1);
	if (ft_issign(line[i]))
		(*j)++;
	while (ft_isdigit(line[i + (*j)]))
		(*j)++;
	if (line[i + (*j)] && (!ft_isspace(line[i + (*j)]) && !(line[i + (*j)] == '.')))
		return (1);
	if (line[i + (*j)] == '.')
	{
		(*j)++;
		while (ft_isdigit(line[i + (*j)]))
			(*j)++;
	}
	if (line[i + (*j)] && (!ft_isspace(line[i + (*j)])))
		return (1);
	return (0);
}