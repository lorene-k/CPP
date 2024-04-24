/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:11:55 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/24 12:58:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->pipes)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
	}
}

void	close_files(t_data *data)
{
	if (data->in)
		close(data->in);
	if (data->out)
		close(data->out);
	if (data->here_doc)
		unlink("heredoc_tmp");
}

void	clear_all(t_data *data)
{
	close_files(data);
	if (data->cmd.paths)
		clear_tab(data->cmd.paths);
	if (data->fd)
		clear_int_tab(data->fd, data->pipes);
	if (data->epath)
		free(data->epath);
	if (data->pid)
		free(data->pid);
	if (data->infile)
		free(data->infile);
}
