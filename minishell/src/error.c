/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:27:37 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/24 22:59:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int print_error(char *msg, int code)
{
    ft_putstr_fd("minishell", 2);
    ft_putendl_fd(msg, 2);
    return(code);
}

static void	print_file_error(char *file, char *str, int file_err)
{
	if (file_err)
		ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(str, 2);
}

// void	put_cmd_error(char *cmd, t_data *data)
// {
// 	print_file_error(cmd, INVALID_COMMAND, 0);
// 	clear_tab(data->cmd.args);
// 	clear_all(data);
// 	if (errno == EACCES)
// 		exit(126);
// 	exit(127);
// }

void	check_error(char *file, int n, t_data *data)
{
	if (n == 0)
	{
		if (errno == EACCES)
			print_file_error(file, BAD_ACCESS, 1);
		else if (errno == ENOENT)
			print_file_error(file, UNEXISTING_FILE, 1);
	}
	else if (errno == ENOENT)
		print_file_error(file, UNEXISTING_FILE, 1);
	else if (errno == EACCES)
		print_file_error(file, BAD_ACCESS, 1);
    clear_cmds(&(data->cmd)); //MAKE SURE CMDS ARE CLEARED FROM THE START
}