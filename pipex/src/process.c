 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:28:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/11 18:08:28 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_data *data, char **av, char **envp)
{
	int *status;

	status = 0;
	if (waitpid(-1, status, 0) == -1)
		print_error("waitpid", *status, data); // ERR_CODE //get status exit code from children, if it is != 0, exit w/ it
	redirect(data->fd[data->i - 1][0], data->out, data);
	close_pipes(data);
	// if (status)
	// 	put_child_error("msg", data, status);
	ft_exec(data, envp, av[2 + data->i + data->here_doc]);
	clear_all(data);
}

void	ft_exec(t_data *data, char **envp, char *cmd)
{
	data->cmd.args = ft_split(cmd, ' ');
	data->cmd.c_path = get_c_path(data->cmd.paths, data->cmd.args[0], data);
	if (!data->cmd.c_path)
		put_child_error("c_path", data, EXIT_FAILURE); //CHECK ERR
	if (execve(data->cmd.c_path, data->cmd.args, envp) == -1)
		put_child_error("execve", data, EXIT_FAILURE); //CHECK ERR //cmd not found : a la main
	clear_tab(data->cmd.args);
	free(data->cmd.c_path);
}

void	redirect(int input, int ouput, t_data *data)
{
	if (dup2(input, STDIN_FILENO))
		put_child_error("pipex: dup2", data, EXIT_FAILURE);
	if (dup2(ouput, STDOUT_FILENO))
		put_child_error("pipex: dup2", data, EXIT_FAILURE);
}

void	child(t_data *data, char **av, char **envp)
{
	data->pid = fork();
	if (data->pid == -1)
		print_error("pipex", EXIT_FAILURE, data);
	if (data->pid == 0)
	{
		if (data->i == 0)
			redirect(data->in, data->fd[0][1], data);
		else
			redirect(data->fd[data->i - 1][0], data->files[data->i - 1], data);
		close_pipes(data);
		ft_exec(data, envp, av[2 + data->i + data->here_doc]);
	}
}
