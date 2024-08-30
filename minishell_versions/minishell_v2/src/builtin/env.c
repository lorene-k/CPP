/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:55:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/25 13:14:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_infos *infos, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args_indexes > 2)
		return (print_cmd_error("env: too many arguments", infos, 125));
	while (infos->new_envp[i] != NULL)
	{
		ft_putendl_fd(infos->new_envp[i], 1);
		i++;
	}
	return (0);
}
