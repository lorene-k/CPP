/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:24:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/05 17:49:10 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(char *cmd_path, t_data *data)
{
	if (access(cmd_path, F_OK) == 0)
	{
		if (access(cmd_path, X_OK) == 0)
			return (1);
		else
			put_child_error(data, 126);
	}
	else if (access(cmd_path, X_OK) == 0)
	{
		if (access(cmd_path, F_OK) == 0)
			return (1);
		else
			put_child_error(data, 127);
	}
	return (0);
}

char	*get_c_path(char **paths, char *cmd, t_data *data)
{
	char	*tmp;
	char	*cmd_path;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_access(cmd_path, data))
			return(cmd_path);
		free(cmd_path);
		cmd_path = 0;
		paths++;
	}
	return (0);
}

char	*ft_getenv(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	get_cmds(int ac, t_data *data, char **envp)
{
	data->cmd.n = ac - data->here_doc - 3;
	data->pipes = data->cmd.n - 1;
	data->epath = ft_getenv(envp);
	data->cmd.paths = ft_split(data->epath, ':');
	if (!data->cmd.paths)
		print_error("malloc", EXIT_FAILURE, data); //ERR_CODE //close in & out + free cmd.paths
}
