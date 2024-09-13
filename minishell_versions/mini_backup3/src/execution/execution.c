/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:21:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 17:22:03 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Ferme tous les descripteurs de fichiers associés a un pipe
void	close_all_pipe(t_infos *infos)
{
	int	i;

	i = 0;
	while (i < infos->pipes_nb)
	{
		close(infos->tube[i * 2]);
		close(infos->tube[(i * 2 + 1)]);
		i++;
	}
}

// Attend la fin de tous les processus fils
static void	wait_all_cmds(t_infos *infos)
{
	int	i;
	int	status;

	i = 0;
	status = -1;
	while (i < infos->cmd_nb)
	{
		waitpid(infos->pid[i], &status, 0);
		i++;
	}
	if (sig_id == 128 + SIGINT)
	{
		infos->return_code = 128 + SIGINT;
		sig_id = 128 + SIGINT;
	}
	else
	{
		infos->return_code = WEXITSTATUS(status);
		sig_id = WEXITSTATUS(status);
	}
}

// Ferme les descripteurs de fichier APPEND TRUNC ET HEREDOC
static void	close_other_fd(t_infos *infos)
{
	int	i;

	i = 0;
	while (i < infos->cmd_nb)
	{
		if (infos->cmd[i]->intype == FILE_REAL
			|| infos->cmd[i]->intype == HEREDOC)
			close(infos->cmd[i]->fd_in);
		if (infos->cmd[i]->outtype == APPEND
			|| infos->cmd[i]->outtype == HEREDOC)
			close(infos->cmd[i]->fd_out);
		i++;
	}
}

// Execute toutes les commandes (avec pipes ou non)
static void	execute_all_cmds(t_infos **infos)
{
	int	i;
	int	actual_pipe_id;

	i = 0;
	actual_pipe_id = 0;
	(*infos)->pid = malloc(sizeof(int) * (*infos)->cmd_nb);
	if (!(*infos)->pid)
		protect_memory(*infos, NULL, NULL);
	while (i < (*infos)->cmd_nb)
	{
		if ((*infos)->cmd[i]->outtype == PIPE)
			child(infos, (*infos)->cmd[i], i, actual_pipe_id);
		else if ((*infos)->cmd[i]->intype == PIPE)
		{
			child(infos, (*infos)->cmd[i], i, actual_pipe_id);
			actual_pipe_id++;
		}
		else
			child(infos, (*infos)->cmd[i], i, actual_pipe_id);
		i++;
	}
}

// Lance l'execution d'une ou plusieurs commanes (builtin ou non)
void	execute(t_infos **infos)
{
	if ((*infos)->sigint_heredoc == 1)
		return ;
	signals_init_execution();
	if ((*infos)->cmd_nb == 1 && is_builtin((*infos)->cmd[0]->args[0]))
	{
		execute_one_builtin(*infos, 0);
		return ;
	}
	else
	{
		execute_all_cmds(infos);
		close_all_pipe(*infos);
		wait_all_cmds(*infos);
		close_other_fd(*infos);
	}
	signals_init();
}
