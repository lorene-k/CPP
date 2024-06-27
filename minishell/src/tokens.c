/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/27 16:57:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void    init_token(t_token **start)
{
    t_token *token;
    
    token = malloc(sizeof(t_token));
    if (!token)
        return ;
    token->value = 0;
    token->type = 0;
    token->next = 0;
    token->prev = 0;
    *start = token;
}

void	add_token(t_token **start)
{
	t_token	*token;

	if (!*start)
	{
		init_token(start);
		return ;
	}
	token = malloc(sizeof(t_token));
	if (!token)
	{
		clear_tokens(start);
		*start = NULL;
		return ;
	}
    token->value = 0;
    token->type = 0;
    token->next = 0;
    token->prev = *start;
    (*start)->next = token;
}
