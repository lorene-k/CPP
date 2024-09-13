/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:07:16 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 17:27:04 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	select_builtin(t_infos **infos, int id)
{
	int	return_code;

	return_code = 0;
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "echo"))
		return_code = ft_echo(*infos, (*infos)->cmd[id]);
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "pwd"))
		return_code = ft_pwd(*infos, (*infos)->cmd[id]);
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "env"))
		return_code = ft_env(*infos, (*infos)->cmd[id]);
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "export"))
		return_code = ft_export(*infos, (*infos)->cmd[id]);
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "unset"))
		return_code = ft_unset(*infos, (*infos)->cmd[id]);
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "cd"))
		return_code = ft_cd(*infos, (*infos)->cmd[id]);
	if (!ft_strcmp((*infos)->cmd[id]->args[0], "exit"))
		return_code = ft_exit(*infos, (*infos)->cmd[id]);
	return (return_code);
}

int	execute_one_builtin(t_infos *infos, int id)
{
	int	fds[2];

	if (!infos->cmd[id]->can_access_file)
	{
		sig_id = 1;
		return (1);
	}
	fds[0] = dup(0);
	fds[1] = dup(1);
	dup2(infos->cmd[id]->fd_out, 1);
	dup2(infos->cmd[id]->fd_in, 0);
	infos->return_code = select_builtin(&infos, id);
	dup2(fds[1], 1);
	dup2(fds[0], 0);
	sig_id = infos->return_code;
	return (infos->return_code);
}

static void	check_child_error(t_infos ***infos, t_cmd *cmd)
{
	int	exit_code;

	if (!cmd->can_access_file)
		exit(1);
	if (cmd->cmd_not_found)
	{
		if (cmd->cmd_not_found == 2)
			ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		if (cmd->cmd_not_found == 2)
		{
			ft_putendl_fd(" : Permission denied", 2);
			exit_code = 126;
		}
		else
		{
			ft_putendl_fd(" : command not found", 2);
			exit_code = 127;
		}
		close_all_pipe(**infos);
		free_infos_child(*infos);
		exit(exit_code);
	}
}

static void	check_builtin(t_infos **infos, t_cmd *cmd, int id)
{
	int	return_code;

	return_code = 0;
	if (is_builtin(cmd->args[0]))
	{
		return_code = execute_one_builtin(*infos, id);
		free_infos_child(infos);
		exit(return_code);
	}
}

// Crée le processus puis execute la commande
void	child(t_infos **infos, t_cmd *cmd, int id, int actual_pipe_id)
{
	char	*cmd_path;

	(*infos)->pid[id] = fork();
	if ((*infos)->pid[id] == 0)
	{
		check_child_error(&infos, cmd);
		dup2(cmd->fd_out, 1);
		dup2(cmd->fd_in, 0);
		close_all_pipe(*infos);
		check_builtin(infos, cmd, id);
		if (cmd->can_access_file && cmd->cmd_not_found != 1)
			execve(cmd->path, cmd->args, (*infos)->new_envp);
		else
			exit(1);
	}
	else if ((*infos)->pid[id] < 0)
	{
		perror("minishell");
		free_infos_error(*infos);
	}
}

// int	execute_one_builtin(t_infos *infos, int id)
// {
// 	int	fds[2];

// 	if (!infos->cmd[id]->can_access_file)
// 	{
// 		sig_id = 1;
// 		return (1);
// 	}
// 	fds[0] = dup(0);
// 	fds[1] = dup(1);
// 	dup2(infos->cmd[id]->fd_out, 1);
// 	dup2(infos->cmd[id]->fd_in, 0);
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "echo"))
// 		(infos->return_code = ft_echo(infos, infos->cmd[id]));
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "pwd"))
// 		(infos->return_code = ft_pwd(infos, infos->cmd[id]));
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "env"))
// 		(infos->return_code = ft_env(infos, infos->cmd[id]));
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "export"))
// 		(infos->return_code = ft_export(infos, infos->cmd[id]));
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "unset"))
// 		(infos->return_code = ft_unset(infos, infos->cmd[id]));
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "cd"))
// 		(infos->return_code = ft_cd(infos, infos->cmd[id]));
// 	if (!ft_strcmp(infos->cmd[id]->args[0], "exit"))
// 		(infos->return_code = ft_exit(infos, infos->cmd[id]));
// 	dup2(fds[1], 1);
// 	dup2(fds[0], 0);
// 	sig_id = infos->return_code;
// 	return (infos->return_code);
// }

// // Crée le processus puis execute la commande
// static void child(t_infos **infos, t_cmd *cmd, int id, int actual_pipe_id)
// {

//     char    *cmd_path;
//     int return_code;

//     (*infos)->pid[id] = fork();
//     if((*infos)->pid[id] == 0)
//     {

//         if (!cmd->can_access_file)
//             exit(1);
//         if (cmd->cmd_not_found)
//         {
//             if (cmd->cmd_not_found == 2)
//                 ft_putstr_fd("minishell: ", 2);
//             ft_putstr_fd(cmd->args[0], 2);
//             if (cmd->cmd_not_found == 2)
//                 ft_putendl_fd(" : Permission denied", 2);
//             else
//                 ft_putendl_fd(" : command not found", 2);
//             close_all_pipe(*infos);
//             free_infos_child(infos);
//             if (cmd->cmd_not_found == 2)
// 					exit(126);
// 				exit(127);
//         }
//         dup2(cmd->fd_out, 1);
//         dup2(cmd->fd_in, 0);
//         close_all_pipe(*infos);
//         if(is_builtin(cmd->args[0]))
//         {
//             return_code = execute_one_builtin(*infos, id);
//             free_infos_child(infos);
//             exit(return_code);
//         }
//         else
//         {
//             if (cmd->can_access_file && cmd->cmd_not_found != 1)
//                 execve(cmd->path, cmd->args, (*infos)->new_envp);
//             else
//                 exit(1);
//         }
//     }
//     else if ((*infos)->pid[id] < 0)
//     {
//         perror("minishell");
//         free_infos_error(*infos);
//     }

// }