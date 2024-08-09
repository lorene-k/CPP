/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/09 15:59:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	clear_cmd_node(t_cmd *cmd)
{
	clear_tab(cmd->args);
	clear_tab(cmd->paths);
	if (cmd->name)
		free(cmd->name);
	if (cmd->c_path)
		free(cmd->c_path);
	free(cmd);
}

void	clear_files(t_file **start)
{
	t_file	*current;
	t_file	*next;

	if (!start || !*start)
		return ;
	current = (*start);
	while (current)
	{
		next = current->next;
		if (current->name)
			free(current->name);
		if (current->limiter)
			free(current->limiter);
		free(current);
		current = next;
	}
	*start = NULL;
}

void	clear_cmds(t_cmd **start)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!start || !*start)
		return ;
	current = (*start);
	while (current)
	{
		next = current->next;
		clear_files(&(current->file));
		clear_cmd_node(current);
		current = next;
	}
	*start = NULL;
}

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
	*start = NULL;
}
