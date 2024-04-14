/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:51:41 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/13 12:56:56 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pipes)
	{
		if (pipe(data->fd[i]) < 0)
		{
			close_pipes(data);
			print_error("pipe", EXIT_FAILURE, data); //CHECK ERR
		}
		i++;
	}
}

void	get_fd(t_data *data)
{
	int	i;

	i = -1;
	data->fd = malloc(sizeof(int *) * data->pipes);
	if (!data->fd)
		print_error("malloc", EXIT_FAILURE, data); //CHECK ERR //close in & out, free paths
	while (++i < data->pipes)
	{
		data->fd[i] = malloc(sizeof(int) * 2);
		if (!data->fd[i])
			print_error("malloc", EXIT_FAILURE, data); //CHECK ERR //close in & out, free paths, free fd's
		ft_memset(data->fd[i], -1, 2);
	}
}

void	init_all(t_data *data)
{
	data->i = -1;
	data->in = -1;
	data->out = -1;
	data->pid = 0;
	data->pipes = 0;
	data->epath = 0;
	data->cmd.n = 0;
	data->cmd.paths = 0;
	data->cmd.args = 0;
	data->cmd.c_path = 0;
	data->here_doc = 0;
	data->limiter = 0;
}

t_data	init_data(int ac, char **av, char **envp)
{
	t_data data;

	init_all(&data);
	get_files(ac, av, &data);
	get_cmds(ac, &data, envp);
	get_fd(&data);
	get_pipes(&data);
	return (data);
}