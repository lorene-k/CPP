/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/01 16:11:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void clear_data(t_data *data)
{
	// clear_fds
	// clear_pids
	// clear_epath
	if (data->limiter)
		free(data->limiter);
}

static void clear_node(t_cmd *cmd)
{
	clear_tab(cmd->args);
	clear_tab(cmd->paths);
	if (cmd->name)
		free(cmd->name);
	if (cmd->c_path)
		free(cmd->c_path); 
	free(cmd);
}

void clear_cmds(t_cmd **start)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!start || !*start)
		return ;
	current = (*start);
	while (current)
	{
		next = current->next;
		clear_node(current);
		current = next;
	}
	*start = NULL;
}

void	clear_all(t_data *data)
{
	clear_cmds(&(data->cmd));
	clear_data(data);
	rl_clear_history();
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
