/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:27:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/18 15:40:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *msg, int exit_code, t_data *data)
{
	perror(msg);
	if (data)
		clear_all(data);
	exit(exit_code);
}

void	check_error(char *file)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putendl_fd(file, 2);
	}
}