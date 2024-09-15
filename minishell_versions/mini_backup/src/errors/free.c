/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:12:55 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 16:16:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Free tous les arguments de la commande et la commande
void	free_cmd_args(t_cmd *cmd)
{
	int	id;

	id = 0;
	while (id < cmd->args_indexes)
	{
		if (cmd->args[id] != NULL)
		{
			free(cmd->args[id]);
		}
		id++;
	}
	free(cmd->args);
	cmd->args = NULL;
	cmd->args_indexes = 0;
}

void	free_two_tokens(char *a_token, char *next_token, t_cmd *a_cmd, int id)
{
	free(a_token);
	free(next_token);
	a_cmd->args[id] = NULL;
	a_cmd->args[id + 1] = NULL;
}

// Free tout ce qui a été créé pendant la phase de parsing
static void	free_parsing(t_infos **infos, char *input)
{
	int		i;
	int		arg_id;
	t_cmd	*actual_cmd;

	i = 0;
	arg_id = 0;
	if (*infos == NULL)
		return ;
	while (i < (*infos)->cmd_nb)
	{
		actual_cmd = (*infos)->cmd[i];
		free_cmd_args(actual_cmd);
		if (actual_cmd->intype != NORMAL && actual_cmd->intype != PIPE
			&& actual_cmd->intype != HEREDOC)
			free(actual_cmd->infile);
		if (actual_cmd->outtype != NORMAL && actual_cmd->outtype != PIPE)
			free(actual_cmd->outfile);
		if (actual_cmd->heredoc != NULL)
			free(actual_cmd->heredoc);
		if (actual_cmd->path != NULL)
			free(actual_cmd->path);
		free(actual_cmd);
		i++;
	}
	free((*infos)->cmd);
}

// Free tout a la fin du programme
void	free_all(t_infos **infos, char *input)
{
	free_parsing(infos, input);
	clear_tab((*infos)->paths);
	if ((*infos)->tube != NULL)
		free((*infos)->tube);
	if ((*infos)->pid != NULL)
		free((*infos)->pid);
	free(*infos);
}
