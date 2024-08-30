/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:01:52 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/25 13:01:53 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_infos *infos, t_cmd *cmd)
{
	char	buffer[1024];

	(void)cmd;
	(void)infos;
	if (!getcwd(buffer, 1024))
		return (print_cmd_error("getcwd : failed to allocate buffer", 0, 1));
	else
	{
		ft_putendl_fd(buffer, 1);
		return (0);
	}
}
