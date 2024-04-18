/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/14 08:25:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_cmd_error(t_data *data)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(data->cmd.args[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	clear_tab(data->cmd.args);
	free(data->cmd.c_path);
	exit(127);
}

void	put_child_error(char *msg, t_data *data, int exit_code)
{
	if (data->cmd.args)
		clear_tab(data->cmd.args);
	if (data->cmd.c_path)
		free(data->cmd.c_path);
	perror(msg);
	exit(exit_code);
}

void	print_error(char *msg, int exit_code, t_data *data)
{
	perror(msg);
	if (data)
		clear_all(data);
	exit(exit_code);
}
