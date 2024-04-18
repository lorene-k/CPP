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
	int status;

	status = 0;
	close_pipes(data);
	if (waitpid(-1, &status, 0) == -1)
		print_error("waitpid", status, data);
	clear_all(data);
	exit(WEXITSTATUS(status));
}

void	ft_exec(t_data *data, char **envp, char *cmd)
{
	data->cmd.args = ft_split(cmd, ' ');
	data->cmd.c_path = get_c_path(data->cmd.paths, data->cmd.args[0]);
	if (execve(data->cmd.c_path, data->cmd.args, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit(127);
	}
}

void	redirect(int input, int output, t_data *data)
{
	dup2(input, STDIN_FILENO);
	dup2(output, STDOUT_FILENO);
	close_pipes(data);
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
		else if (data->i == data->cmd.n - 1)
			redirect(data->fd[data->i - 1][0], data->out, data);
		else
			redirect(data->fd[data->i - 1][0], data->fd[data->i][1], data);
		ft_exec(data, envp, av[2 + data->i + data->here_doc]);
	}
}
