/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_unclosed_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:03:10 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 14:29:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_type(t_token **token)
{
	int	j;

	j = 0;
	if (!check_operator((*token)->value, 0, &j))
		get_type(*token, 3);
	else if (!check_digit((*token)->value, 0, &j))
		get_type(*token, 2);
	else if (ft_isalpha(*(*token)->value) || !ft_isascii(*(*token)->value)
		|| j != (int)ft_strlen((*token)->value))
		get_type(*token, 1);
}

static void	check_quoted_input(char *buf, int i, t_token **token, t_data *d)
{
	char	*tmp;

	tmp = NULL;
	if (buf[i + 2] || buf[i + 1] != '\n')
	{
		tmp = ft_substr(buf, i + 1, ft_strlen(buf) - i - 2);
		(*token) = lexer(*token, tmp, d);
		free(tmp);
	}
	free(buf);
}

static int	get_quoted_input(char **buf, char **tmp, char quote)
{
	int	i;

	(*buf) = ft_strjoin_memory(readline("> "), ft_strdup("\n"));
	while (1)
	{
		i = ft_strchr_index((*buf), quote);
		if (i != -1 && ft_count_chars((*buf), quote) % 2 != 0)
			break ;
		(*buf) = ft_strjoin_memory((*buf), readline("> "));
		(*buf) = ft_strjoin_gnl((*buf), "\n");
	}
	(*tmp) = ft_substr((*buf), 0, i);
	return (i);
}

void	handle_unclosed_quote(char quote, t_token **token, t_data *d)
{
	char	*buf;
	int		i;

	buf = NULL;
	if ((*token)->value)
		(*token)->value = ft_strjoin_memory((*token)->value, ft_strdup("\n"));
	else
		(*token)->value = ft_strdup("\n");
	free(d->line);
	i = get_quoted_input(&buf, &(d->line), quote);
	check_expansion(token, d);
	check_type(token);
	check_quoted_input(buf, i, token, d);
}
