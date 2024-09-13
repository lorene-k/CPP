/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:57:40 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 14:36:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_infos *infos, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (check_builtin_error(cmd, "env"))
		return (1);
	if (cmd->args_indexes > 2)
		return (print_cmd_error("env: too many arguments", infos, 125));
	while (infos->new_envp[i] != NULL)
	{
		if (ft_strchr(infos->new_envp[i], '=') != NULL)
			ft_putendl_fd(infos->new_envp[i], 1);
		i++;
	}
	return (0);
}
