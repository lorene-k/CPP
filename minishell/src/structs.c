/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/29 16:20:18 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*get_first_cmd(t_cmd *last)
{
	t_cmd	*curr;

	if (!last)
		return (NULL);
	curr = last;
	while (curr->prev)
		curr = curr->prev;
	return (curr);
}

t_token	*get_first_token(t_token *last)
{
	t_token	*curr;

	if (!last)
		return (NULL);
	curr = last;
	while (curr->prev)
		curr = curr->prev;
	return (curr);
}

static void init_cmd(t_cmd *cmd)
{
	cmd->name = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->in_fd = -1;
	cmd->out_fd = -1;
	cmd->append = 0;
	cmd->next = 0;
	cmd->prev = 0;
	cmd->builtin = 0;
}

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
	init_cmd(cmd);
	if (!*current)
		*current = cmd;
	else
	{
		(*current)->next = cmd;
		cmd->prev = *current;
		*current = cmd;
	}
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
