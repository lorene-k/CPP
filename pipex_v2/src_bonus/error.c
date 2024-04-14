/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/12 13:29:15 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	check_error(t_data *data, char *file)
{
	if (errno == ENOENT)
		print_error(file, 2, data);
	else if (errno == EACCES)
		print_error(file, EXIT_FAILURE, data);
}