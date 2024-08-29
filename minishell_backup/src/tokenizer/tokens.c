/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:48:26 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/29 18:31:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*store_token(t_token *curr, t_token **token, t_infos *infos)
{
	char	*str;

	str = malloc(sizeof(char) * curr->len + 1);
	if (!str)
		return (NULL); //CHANGED
	str[0] = '\0';
	ft_strlcpy(str, curr->value, curr->len + 1);
	return (str);
}

static char	**token_to_str(t_token **token, int n_nodes, t_infos *infos)
{
	int		i;
	char	**token_tab;
	t_token	*curr;

	i = -1;
	curr = *token;
	token_tab = malloc(sizeof(char *) * (n_nodes + 1));
	if (!token_tab)
		return (print_memory_error(infos, token_tab, *token));
	token_tab[n_nodes] = NULL;
	while (++i < n_nodes)
	{
		token_tab[i] = store_token(curr, token, infos);
		if (!token_tab[i])
			return ((char **)print_memory_error(infos, token_tab, *token));
		curr = curr->next;
	}
	clear_tokens(token);
	return (token_tab);
}

static t_token	*create_tokens(char *line, t_infos *infos, int *n_nodes)
{
	int		i;
	t_token	*token;

	i = 0;
	token = NULL;
	(void)infos;
	while (i < (int)ft_strlen(line))
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '#' || !line[i]) //CHANGED
			break ;
		*n_nodes += add_token_node(&token, infos);
		if (!token)
			return (print_memory_error(infos, NULL, token));
		get_token_value(line, &i, &token, infos);
		if (token->error) //CHANGED
			return (clear_tokens(&token), NULL);
		token->len = ft_strlen(token->value);
	}
	return (get_first_node(token));
}

char	**generate_tokens_array(char *line, t_infos *infos)
{
	int		n_nodes;
	t_token	*token;
	char	**token_tab;

	n_nodes = 0;
	token = NULL;
	token = create_tokens(line, infos, &n_nodes);
	if (!token || check_invalid_tokens(token, infos))
		return (NULL);
	return (token_to_str(&token, n_nodes, infos));
}

//SPACES - OK
//DELETE CHECK_EXPANSION - OK
//PROTECT MALLOCS - OK
//CORRECT SYNTAX ERROR CHECKING