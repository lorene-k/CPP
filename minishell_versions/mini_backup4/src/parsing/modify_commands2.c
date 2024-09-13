#include "minishell.h"
#include <sys/stat.h>
#include <sys/types.h>

// on indique si la commande utilise entrée et sortie standard ou pipes
void	set_in_out_pipes_and_normal(t_infos **infos)
{
	int		i;
	int		arg_id;
	t_cmd	*actual_cmd;

	i = 0;
	arg_id = 0;
	if ((*infos)->pipes_nb >= 1)
	{
		while (i < (*infos)->cmd_nb)
		{
			actual_cmd = (*infos)->cmd[i];
			if (actual_cmd->outtype == NORMAL && i + 1 < (*infos)->cmd_nb)
			{
				if ((*infos)->cmd[i + 1]->intype == NORMAL)
				{
					actual_cmd->outtype = PIPE;
					(*infos)->cmd[i + 1]->intype = PIPE;
				}
				else if (((*infos)->cmd[i + 1]->intype == HEREDOC)
						|| ((*infos)->cmd[i + 1]->intype == FILE_REAL))
					actual_cmd->outtype = PIPE;
			}
			i++;
		}
	}
}

// Retourne le chemin absolu d'une commande si ok sinon renvoi NULL
char	*absolute_path(t_infos **infos, char **all_paths, char *cmd)
{
	char	*temp;
	char	*actual_command;

	while (*all_paths)
	{
		temp = ft_strjoin(*all_paths, "/");
		if (!temp)
			return (free_infos_error(*infos), NULL);
		actual_command = ft_strjoin(temp, cmd);
		free(temp);
		if (!actual_command)
			return (free_infos_error(*infos), NULL);
		if (access(actual_command, F_OK | X_OK) == 0)
			return (actual_command);
		free(actual_command);
		all_paths++;
	}
	return (NULL);
}

// Retourne le chemin dune commande a partir de son nom echo retourne /bin/echo
static char	*command_path_parsing(t_infos **infos, char *cmd)
{
	char	*temp;
	char	*actual_command;
	char	**all_paths;

	all_paths = (*infos)->paths;
	if (env_var_exists(*infos, "PATH") == 0)
		return (NULL);
	if (!all_paths)
		return (NULL);
	if ((ft_strlen(cmd) > 2 && cmd[0] == '.' && cmd[1] == '/')
		|| (ft_strlen(cmd) > 1 && cmd[0] == '/') || (ft_strlen(cmd) > 2
			&& ft_strchr(cmd, '/') != NULL))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (cmd);
		if (errno == EACCES)
			return (NULL);
	}
	return (absolute_path(infos, all_paths, cmd));
}

static void	rename_one_cmd(t_cmd *cmd, t_infos **infos)
{
	char	*temp;

	if (ft_strchr(cmd->args[0], '/'))
	{
		temp = ft_strdup(ft_strrchr(cmd->args[0], '/') + 1);
		if (!temp)
			protect_memory(*infos, 0, 0);
		cmd->args[0] = temp;
	}
}

// Retourne 1 si le parametre est un dossier, si c'est une commande renvoi 0
int	is_dir(t_cmd *cmd, t_infos **infos)
{
	struct stat	buf;
	int			ret;

	if (ft_strchr(cmd->args[0], '/'))
	{
		ret = stat(cmd->args[0], &buf);
		if (S_ISDIR(buf.st_mode))
			return (1);
	}
	else
	{
		return (0);
	}
	return (0);
}

// Retourne 1 si le fichier ou dossier existe, si c'est une commande renvoi 1
int	file_or_directory_exists(t_cmd *cmd, t_infos **infos)
{
	struct stat	buf;
	int			ret;

	if (ft_strchr(cmd->args[0], '/'))
	{
		ret = stat(cmd->args[0], &buf);
		if (ret < 0)
			return (0);
	}
	return (1);
}

// Si on peut acceder a la commande alors associe path sinon met le code erreur
void	check_and_assign_path(t_cmd *actual_cmd, t_infos **infos)
{
	if (file_or_directory_exists(actual_cmd, infos))
	{
		if (is_dir(actual_cmd, infos))
			actual_cmd->cmd_not_found = 3;
		else
		{
			actual_cmd->path = command_path_parsing(infos, actual_cmd->args[0]);
			if (!(actual_cmd->path))
			{
				if (errno == EACCES)
					actual_cmd->cmd_not_found = 2;
				else
					actual_cmd->cmd_not_found = 1;
			}
			rename_one_cmd(actual_cmd, infos);
		}
	}
	else
	{
		actual_cmd->cmd_not_found = 4;
	}
}

// Associe le path pour execve a chaque commande
int	set_all_cmd_path(t_infos **infos, char **envp)
{
	t_cmd	*actual_cmd;
	int		i;

	i = 0;
	while (i < (*infos)->cmd_nb)
	{
		actual_cmd = (*infos)->cmd[i];
		actual_cmd->cmd_not_found = 0;
		if (!is_builtin(actual_cmd->args[0]))
		{
			check_and_assign_path(actual_cmd, infos);
		}
		i++;
	}
	return ((*infos)->return_code);
}
