/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/13 17:11:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return(ft_putstr_fd("pipex : Invalid number of arguments\n", 2), 0);
	data = init_data(ac, av, envp);
	
	while (data.i++ < data.pipes)
		ft_printf("fd : %d - i : %d\n", data.files[data.i], data.i);
	exit(0);
		child(&data, av, envp);
	parent(&data, av, envp);
	return (0);
}
