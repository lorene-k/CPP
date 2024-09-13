/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:37:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 16:56:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_pipes(t_infos ***infos)
{
	int	i;

	i = 0;
	while (i < (**infos)->pipes_nb * 2)
	{
		if (pipe((**infos)->tube + (i)) < 0)
		{
			perror("minishell");
			free_infos_error(**infos);
		}
		i += 2;
	}
}

void	create_pipes(t_infos **infos)
{
	int	i;
	int	z;

	i = 0;
	(*infos)->tube = malloc(sizeof(int) * (*infos)->pipes_nb * 2);
	if (!(*infos)->tube)
		protect_memory(*infos, 0, 0);
	get_pipes(&infos);
	z = 0;
	while (i < (*infos)->cmd_nb)
	{
		if ((*infos)->cmd[i]->outtype == PIPE)
		{
			(*infos)->cmd[i]->fd_out = (*infos)->tube[(z * 2) + 1];
			(*infos)->cmd[i + 1]->fd_in = (*infos)->tube[z * 2];
			z++;
		}
		i++;
	}
}

// void	create_pipes(t_infos **infos)
// {
// 	int	i;
// 	int	z;

// 	i = 0;
// 	(*infos)->tube = malloc(sizeof(int) * (*infos)->pipes_nb * 2);
// 	if (!(*infos)->tube)
// 		protect_memory(*infos, 0, 0);
// 	while (i < (*infos)->pipes_nb * 2)
// 	{
// 		if (pipe((*infos)->tube + (i)) < 0)
// 		{
// 			perror("minishell");
// 			free_infos_error(*infos);
// 		}
// 		i += 2;
// 	}
// 	i = 0;
// 	z = 0;
// 	while (i < (*infos)->cmd_nb)
// 	{
// 		if ((*infos)->cmd[i]->outtype == PIPE)
// 		{
// 			(*infos)->cmd[i]->fd_out = (*infos)->tube[(z * 2) + 1];
// 			(*infos)->cmd[i + 1]->fd_in = (*infos)->tube[z * 2];
// 			z++;
// 		}
// 		i++;
// 	}
// }
