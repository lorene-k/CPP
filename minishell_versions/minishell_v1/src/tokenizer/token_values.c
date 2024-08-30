/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:31:48 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/29 18:32:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchr_index(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((int)i);
		i++;
	}
	if (*s == (char)c)
		return ((int)i);
	return (-1);
}

static void	handle_quotes(char *line, int *i, t_token **token, t_infos *infos)
{
	int	j;

	j = 1;
	if (line[*i] == '\'')
		(*token)->s_quote = 1;
	while (line[*i + j] && line[*i + j] != line[*i])
		j++;
	if (!line[*i + j] && line[*i + j - 1] != line[*i])
	{
		print_parse_error(infos, 0, QUOTE_ERR);
		(*token)->error = 1;
		return ;
	}
	if (line[*i + j] && j != 1)
		(*token)->value = ft_substr(line, *i + 1, j - 1);
	if (!(*token)->value && !ft_isspace(line[*i + j - 1]))
	{	
		clear_tokens(token);
		protect_memory(infos, 0, 0);
	}
	*i += j + 1;
}

static void	get_str(char *line, int *i, t_token **token, t_infos *infos)
{
	int	j;

	j = 0;
	while (line[*i + j] && !ft_isspace(line[*i + j]) && line[*i + j] != '\''
		&& line[*i + j] != '\"' && !ft_solo_operator(line, *i + j)
		&& !ft_multi_operator(line, *i + j) && line[*i + j] != '|')
		j++;
	(*token)->value = ft_substr(line, *i, j - 1);
	if (!(*token)->value)
	{	
		clear_tokens(token);
		protect_memory(infos, 0, 0);
	}
	*i += j;
}

static void	get_operator(char *line, int *i, t_token **token, t_infos *infos)
{
	int	j;

	if (ft_solo_operator(line, *i))
		j = 1;
	if (ft_multi_operator(line, *i))
		j = 2;
	(*token)->value = ft_substr(line, *i, j);
	if (!(*token)->value)
	{	
		clear_tokens(token);
		protect_memory(infos, 0, 0);
	}
	*i += j;
}

void	get_token_value(char *line, int *i, t_token **token, t_infos *infos)
{
	if (line[*i] == '\'' || line[*i] == '\"')
		handle_quotes(line, i, token, infos);
	else if (!ft_isoperator(line, *i))
		get_str(line, i, token, infos);
	else if (ft_isoperator(line, *i))
		get_operator(line, i, token, infos);
}
