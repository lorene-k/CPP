/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/05 22:32:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_file	*get_first_file(t_file *last)
{
	t_file	*curr;

	if (!last)
		return (NULL);
	curr = last;
	while (curr->prev)
		curr = curr->prev;
	return (curr);
}

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

static void	init_cmds(t_cmd *cmd)
{
	cmd->name = NULL;
	cmd->args = NULL;
	cmd->paths = NULL;
	cmd->c_path = NULL;
	cmd->next = 0;
	cmd->prev = 0;
	cmd->builtin = 0;
}

static void	init_files(t_file *file)
{
	file->name = NULL;
	file->in = 0;
	file->out = 0;
	file->append = 0;
	file->fd_in = 0;
	file->fd_out = 0;
	file->heredoc = 0;
	file->limiter = NULL;
	file->next = 0;
	file->prev = 0;
}

void	add_file(t_file **current)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
	{
		clear_files(current);
		*current = 0;
		return ;
	}
	init_files(file);
	if (!*current)
		*current = file;
	else
	{
		(*current)->next = file;
		file->prev = *current;
		*current = file;
	}
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
	init_cmds(cmd);
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
