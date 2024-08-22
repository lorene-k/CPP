/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:48:26 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/22 12:44:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// IN HEADER
typedef struct s_infos	t_infos;

typedef struct s_token
{
	char				*value;
	size_t				len;
	int					s_quote;
	struct t_token		*next;
	struct t_token		*prev;
}						t_token;

// LEXER
static void    handle_quotes(char *line, int *i, t_token **token)
{
    char quote;
	int		j;

	quote = line[*i];
	j = 0;
	if (quote = '\'')
		(*token)->s_quote = 1;
	while (line[*i + j] && line[*i + j] != quote)
		j++;
	(*token)->value = ft_substr(line, *i, j);
	*i += j;
}

static void    get_str(char *line, int *i, t_token **token)
{
    int	j;

	j = 0;
	while (line[*i + j] && !ft_isspace(line[*i + j]) && line[*i + j] != '\''
		&& line[*i + j] != '\"' && !ft_solo_operator(line, *i + j)
		&& !ft_multi_operator(line, *i + j) && line[*i + j] != '|')
		j++;
	(*token)->value = ft_substr(line, *i, j);
	*i += j;
}

static void	get_operator(char *line, int *i, t_token **token)
{
	int	j;

	if (ft_solo_operator(line, i))
		j = 1;
	if (ft_multi_operator(line, i))
		j = 2;
	(*token)->value = ft_substr(line, *i, j);
	*i += j;
}

void    get_token(char *line, int *i, t_token **token)
{
    if (line[*i] == '\'' || line[*i] == '\"')
        handle_quotes(line, i, token);
    else if (!ft_isoperator(line[*i]))
        get_str(line, i, token);
    else if (ft_isoperator(line, *i))
        get_operator(line, *i, token);
	(*token)->len = ft_strlen((*token)->value);
}

static char	**token_to_str(t_token *token, int n_nodes)
{
	int		i;
	t_token	*next;
	char	**token_tab;

	i = -1;
	token_tab = malloc(sizeof(char *) * n_nodes + 1);
	if (!token_tab)
		return (clear_tab(token_tab), 0);
	token_tab[n_nodes] = '\0';
	while (++i < n_nodes)
	{
		next = token->next;
		token_tab[i] = malloc(sizeof(char) * token->len + 1);
		if (!token_tab[i])
			return (clear_tab(token_tab), 0);
		token_tab[i][0] = '\0';
		ft_strlcpy(token_tab[i], token->value, token->len);
        token = next;
	}
	return (token_tab);
}

char	**tokenize(char *line, t_infos *infos)
{
	int		i;
	int		n_nodes;
	t_token	*token;

	i = 0;
	n_nodes = 0;
	token = 0;
	while (i < ft_strlen(line))
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '#') // maybe useless
			break ;
		add_token_node(&token, &n_nodes);
		if (!token)
			return (clear_tokens(token), 0);
        get_token(line, &i, &token);
		if (ft_strchr(token->value, '$')) //add quote flag
		    token->value = replace_str_var(infos, token->value); // expansions // test MALLOC
	}
	return (token_to_str(get_first(token), n_nodes));
}
