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

void	parent(t_data *data)
{
	int *status;

	status = 0;
	close_pipes(data);
	if (waitpid(-1, status, 0) == -1)
		print_error("waitpid", *status, data); // ERR_CODE //get status exit code from children, if it is != 0, exit w/ it
	clear_all(data);
	if (status)
		put_child_error("pipex", data, *status);
}

void	ft_exec(t_data *data, char **envp, char *cmd)
{
	data->cmd.args = ft_split(cmd, ' ');
	data->cmd.c_path = get_c_path(data->cmd.paths, data->cmd.args[0], data);
	if (execve(data->cmd.c_path, data->cmd.args, envp) == -1)
		put_cmd_error(data);
	clear_tab(data->cmd.args);
	free(data->cmd.c_path);
}

void	redirect(int input, int output, t_data *data)
{
	if (dup2(input, STDIN_FILENO) < 0)
		put_child_error("pipex: dup2", data, EXIT_FAILURE);
	if (dup2(output, STDOUT_FILENO) < 0)
		put_child_error("pipex: dup2", data, EXIT_FAILURE);
}

void	child(t_data *data, char **av, char **envp)
{
	data->pid = fork();
	if (data->pid == -1)
		put_child_error("pipex: fork", data, EXIT_FAILURE);
	if (data->pid == 0)
	{
		if (data->i == 0)
			redirect(data->in, data->fd[0][1], data);
		else if (data->i == data->cmd.n - 1)
			redirect(data->fd[data->i - 1][0], data->out, data);
		else
			redirect(data->fd[data->i - 1][0], data->fd[data->i][1], data);
		close_pipes(data);
		ft_exec(data, envp, av[2 + data->i + data->here_doc]);
	}
}
