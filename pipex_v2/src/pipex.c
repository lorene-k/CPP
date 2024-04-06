/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/05 17:40:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_all(t_data data)
{
	ft_printf("fd in : %d\n", data.in);
	ft_printf("fd out : %d\n", data.out);
	ft_printf("pipes : %d\n", data.pipes);
	ft_printf("epath : %s\n", data.epath);
	ft_printf("heredoc : %d\n", data.here_doc);
	ft_printf("limiter: %s\n", data.limiter);
	ft_printf("cmd n : %d\n", data.cmd.n);

	int i = 0;
	int j = 0;
	while (i < data.pipes)
	{
		while (j < 2)
		{
			ft_printf("fd[%d][%d]: %d\n", i, j, data.fd[i][j]);
			j++;
		}
		i++;
	}
	close_pipes(&data);
	clear_all(&data);
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		status;

	if (ac < 5)
		return(ft_putstr_fd("pipex : Invalid number of arguments\n", 2), 0);
	data = init_data(ac, av, envp);
	check_all(data);
	status = 0;
	while (++data.i < data.pipes)
		child(&data, av, envp);
	parent(&data, status);
	return (0);
}
