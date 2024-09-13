/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:49 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/13 19:16:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_infos *infos, t_cmd *cmd)
{
	char	buffer[1500];
	char	*pwd;

	(void)infos;
	if (check_builtin_error(cmd, "pwd"))
		return (1);
	if (!getcwd(buffer, sizeof(buffer)))
	{
		perror("getcwd");
		exit(1);
	}
	add_env_var(infos, "PWD", buffer);
	pwd = getenv("PWD");
	if (pwd != NULL)
        ft_putendl_fd(pwd, 1);
    else
        perror("PWD");
	return (0);
}

// int	ft_pwd(t_infos *infos, t_cmd *cmd)
// {
// 	char	buffer[1024];

// 	(void)infos;
// 	if (check_builtin_error(cmd, "pwd"))
// 		return (1);
// 	if (!getcwd(buffer, 1024))
// 	{
// 		ft_putstr_fd("getcwd : failed to allocate buffer", 2);
// 		exit(1);
// 	}
// 	else
// 	{
// 		add_env_var(infos, "PWD", buffer);
// 		ft_putendl_fd(buffer, 1);
// 		return (0);
// 	}
// }
