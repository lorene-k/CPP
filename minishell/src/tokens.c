/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/28 17:53:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

t_token *get_first(t_token *token)
{
	t_token	*first;

	if (!token)
		return (NULL);
	first = token;
	while (first->prev)
        first = first->prev;
    return (first);
}

void	add_token(t_token **current)
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
    token->type = 0;
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
}
