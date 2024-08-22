/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:48:26 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/22 12:43:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// IN HEADER
typedef struct s_info	t_info;

typedef struct s_token
{
	char				*value;
	size_t				len;
	int					s_quote;
	struct t_token		*next;
	struct t_token		*prev;
}						t_token;

void	clear_tokens(t_token **start)
{
	t_token	*current;
	t_token	*next;

	if (!start || !*start)
		return ;
	current = (*start);
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	*start = 0;
}

t_token	*get_first(t_token *token)
{
	t_token	*first;

	if (!token)
		return (0);
	first = token;
	while (first->prev)
		first = first->prev;
	return (first);
}

void	add_token_node(t_token **current, int *n_nodes)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
	{
		clear_tokens(current);
		*current = 0;
		return ;
	}
	token->value = 0;
	token->len = 0;
	token->s_quote = 0;
	token->next = 0;
	token->prev = 0;
	if (!*current)
		*current = token;
	else
	{
		(*current)->next = token;
		token->prev = *current;
		*current = token;
	}
	*n_nodes++;
}

void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = 0;
}
