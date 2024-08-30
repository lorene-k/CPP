/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:48:26 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/25 15:02:28 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*store_token(t_token *curr, t_token **token, t_infos *infos)
{
	char	*str;

	str = malloc(sizeof(char) * curr->len + 1);
	if (!str)
		return ((char *)print_memory_error(infos, &str, *token));
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


// A REVOIR POUR CONVERTIR $? en 130 par ex
static void	check_expansion(t_token **token, t_infos *infos)
{
	int		i;
	char	*tmp;

	// char *tmp2;

	i = ft_strchr_index((*token)->value, '$');
	tmp = ft_strdup((*token)->value);
	// if (!(*token)->s_quote && i != -1 && (*token)->value[i + 1]
	// 	&& ft_isalpha((*token)->value[i + 1]
	// 	|| ((*token)->value[i + 1] == '?' && (!(*token)->value[i + 2]
	// 	|| (*token)->value[i + 2] == ' '))))
	// {
	// 	free((*token)->value);
	// 	(*token)->value = NULL;
	// 	//(*token)->value = replace_str_var(infos, tmp);
	// }

	// tmp2 = 
	(*token)->value = replace_str_var(infos, tmp); // EXPANSION !!!!
	free(tmp);
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
		if (line[i] == '#')
			break ;
		*n_nodes += add_token_node(&token, infos);
		if (!token)
			return (print_memory_error(infos, NULL, token));
		get_token_value(line, &i, &token, infos);
		if (token->error)
			return (clear_tokens(&token), NULL);
		check_expansion(&token, infos);
		token->len = ft_strlen(token->value);
	}
	return (get_first_node(token));
}

// char	**generate_tokens_array(char *line, t_infos *infos)
// {
// 	int		n_nodes;
// 	t_token	*token;
// 	char	**token_tab;

// 	n_nodes = 0;
// 	token = NULL;
// 	token = create_tokens(line, infos, &n_nodes);




// 	if (!token || check_invalid_tokens(token, infos))
// 		return (NULL);
// 	return (token_to_str(&token, n_nodes, infos));
// }



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

	token_tab = token_to_str(&token, n_nodes, infos);

	return (token_tab);
}
