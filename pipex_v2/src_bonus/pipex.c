/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:06:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/11 17:38:40 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return(ft_putstr_fd("pipex : Invalid number of arguments\n", 2), 0);
	data = init_data(ac, av, envp);
	while (++data.i < data.pipes)
		child(&data, av, envp);
	parent(&data, av, envp);
	return (0);
}
