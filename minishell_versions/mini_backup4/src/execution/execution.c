/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:21:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/13 17:34:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (g_sig_id == 128 + SIGINT)
	{
		infos->return_code = 128 + SIGINT;
		g_sig_id = 128 + SIGINT;
	}
	else
	{
		infos->return_code = WEXITSTATUS(status);
		g_sig_id = WEXITSTATUS(status);
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

int	execute_one_builtin(t_infos *infos, int id)
{
	int	fds[2];

	if (!infos->cmd[id]->can_access_file)
	{
		g_sig_id = 1;
		return (1);
	}
	fds[0] = dup(0);
	fds[1] = dup(1);
	dup2(infos->cmd[id]->fd_out, 1);
	dup2(infos->cmd[id]->fd_in, 0);
	infos->return_code = select_builtin(&infos, id);
	dup2(fds[1], 1);
	dup2(fds[0], 0);
	g_sig_id = infos->return_code;
	return (infos->return_code);
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
