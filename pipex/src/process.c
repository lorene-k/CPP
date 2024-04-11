/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:28:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/08 11:49:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_data *data, int status)
{
	close_pipes(data);
	if (waitpid(-1, &status, 0) == -1)
		print_error("waitpid", status, data); // ERR_CODE //get status exit code from children, if it is != 0, exit w/ it
	close_files(data);
	clear_tab(data->cmd.paths);
	clear_int_tab(data->fd, data->pipes);
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

void	redirect(int input, int ouput)
{
	dup2(input, STDIN_FILENO);
	dup2(ouput, STDOUT_FILENO);
}

void	child(t_data *data, char **av, char **envp)
{
	data->pid = fork();
	if (data->pid == -1)
		print_error("pipex", EXIT_FAILURE, data);
	if (data->pid == 0)
	{
		if (data->i == 0)
			redirect(data->in, data->fd[0][1]); //check this
		else if (data->i == data->pipes)
			redirect(data->fd[data->i][0], data->out); //maybe don't put -1
		else
			redirect(data->fd[data->i - 1][0], data->fd[data->i + 1][1]);
		close_pipes(data);
		ft_exec(data, envp, av[2 + data->i + data->here_doc]);
	}
}

/*
If i == 0 (first)
>> standard input redirected to data->in
	&& standard output to write end  of pipe
If i < data->cmd->n - 1 (last)
>> standard input redirected to read end of pipe
	&& standard output to data->out
Else, standard input redirected to read end of previous pipe
	&& standard output to  write end of next pipe 
*/

// use fork + execve + waitpid
// check how parent process works