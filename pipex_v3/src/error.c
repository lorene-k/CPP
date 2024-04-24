/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/24 13:16:51 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_file_error(char *file, char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(str, 2);
}

void	put_in_error(t_data *data)
{
	if (data->in_err > 0)
	{
		if (data->in_err == 0)
			print_file_error(data->infile, BAD_ACCESS);
		else if (data->in_err == 1)
			print_file_error(data->infile, UNEXISTING_FILE);
	}
}

void	put_cmd_error(char *cmd, t_data *data)
{
	print_file_error(cmd, INVALID_COMMAND);
	clear_tab(data->cmd.args);
	clear_all(data);
	if (errno == EACCES)
		exit(126);
	exit(127);
}

void	print_error(char *msg, int exit_code, t_data *data)
{
	perror(msg);
	if (data)
		clear_all(data);
	exit(exit_code);
}

void	check_error(char *file, int fd, t_data *data)
{
	if (fd == 0)
	{
		data->infile = ft_strdup(file);
		if (errno == EACCES)
			data->in_err = 0;
		else if (errno == ENOENT)
			data->in_err = 1;
	}
	else if (errno == ENOENT)
		print_file_error(file, UNEXISTING_FILE);
	else if (errno == EACCES)
		print_file_error(file, BAD_ACCESS);
}
