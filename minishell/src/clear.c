/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/24 18:55:06 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	clear_all(void)
{
	rl_clear_history();
	clear_history();
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
