/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/24 18:54:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_cmd(t_cmd **current)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
	{
		clear_cmds(current);
		*current = 0;
		return ;
	}
	cmd->in = -1;
	cmd->out = -1;
	cmd->next = 0;
	cmd->name = NULL;
	cmd->builtin = 0;
	if (!*current)
		*current = cmd;
	else
	{
		(*current)->next = cmd;
		*current = cmd;
	}
}

t_token	*get_first(t_token *token)
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
