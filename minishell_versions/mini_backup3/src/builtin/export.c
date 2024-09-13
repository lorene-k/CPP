/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:59:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/12 15:44:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*TEST*/
// char	**dup_env(t_infos *infos)
// {
// 	int		i;
// 	char	**new;

// 	i = 0;
// 	while (infos->new_envp[i] != NULL)
// 		i++;
// 	new = ft_calloc(sizeof(char *), (i + 1));
// 	i = 0;
// 	while (infos->new_envp[i] != NULL)
// 	{
// 		new[i] = infos->new_envp[i];
// 		i++;
// 	}
// 	return (new);
// }

/*TEST*/
// static void	show_one_line_export(char *str)
// {
// 	char	*right;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = ft_strlen(str);
// 	if (ft_strchr(str, '=') == NULL)
// 	{
// 		ft_putendl_fd(str, 1);
// 		return ;
// 	}
// 	while (i < len)
// 	{
// 		write(1, &str[i], 1);
// 		if (str[i] == '=')
// 			break ;
// 		i++;
// 	}
// 	write(1, "\"", 1);
// 	if (i < len)
// 		ft_putstr_fd(ft_strchr(str, '=') + 1, 1);
// 	write(1, "\"\n", 2);
// }

/*TEST*/
// void	print_sorted_export_env(t_infos *infos)
// {
// 	int		i;
// 	char	**env;
// 	int		sorted;
// 	char	*tmp;

// 	env = dup_env(infos);
// 	i = 0;
// 	sorted = 0;
// 	while (env[i] != NULL && sorted == 0)
// 	{
// 		i = 0;
// 		sorted = 1;
// 		while (env[i + 1] != NULL)
// 		{
// 			if (env[i + 1] != NULL && ft_strcmp(env[i], env[i + 1]) > 0)
// 			{
// 				tmp = env[i];
// 				env[i] = env[i + 1];
// 				env[i + 1] = tmp;
// 				sorted = 0;
// 			}
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (env[i] != NULL)
// 	{
// 		ft_putstr_fd("declare -x ", 1);
// 		show_one_line_export(env[i++]);
// 	}
// 	free(env);
// }

//OK BUT TOO LONG
// static void	add_var_new(t_infos *infos, char *str)
// {
// 	char	*var_content;
// 	char	*var_key;
// 	int		i;

// 	if (ft_strchr(str, '=') == NULL)
// 		add_env_var(infos, str, NULL);
// 	else
// 	{
// 		i = 0;
// 		var_content = ft_strchr(str, '=') + 1;
// 		var_content = replace_str_var(infos, var_content);
// 		if (!var_content)
// 			protect_memory(infos, 0, 0);
// 		while (str[i] != '=')
// 			i++;
// 		var_key = malloc(sizeof(char) * (i + 1));
// 		if (!var_key)
// 			protect_memory(infos, var_content, 0);
// 		i = 0;
// 		while (str[i] != '=')
// 		{
// 			var_key[i] = str[i];
// 			i++;
// 		}
// 		var_key[i] = '\0';
// 		if (!ft_isalpha(var_key[0]) && !(var_key[0] == '_'))
// 			return (ft_putstr_fd("Invalid variable name\n", 2), free(var_key));
// 		add_env_var(infos, var_key, var_content);
// 		free(var_key);
// 		free(var_content);
// 	}
// }

static char	*get_var_content(t_infos *infos, char *str)
{
	char	*var_content;

	var_content = NULL;
	var_content = ft_strchr(str, '=') + 1;
	var_content = replace_str_var(infos, var_content);
	if (!var_content)
		protect_memory(infos, 0, 0);
	return (var_content);
}

static char	*get_var_key(t_infos *infos, char *str, char *var_content)
{
	int		i;
	char	*var_key;

	i = 0;
	var_key = NULL;
	while (str[i] != '=')
		i++;
	var_key = malloc(sizeof(char) * (i + 1));
	if (!var_key)
		protect_memory(infos, var_content, 0);
	i = 0;
	while (str[i] != '=')
	{
		var_key[i] = str[i];
		i++;
	}
	var_key[i] = '\0';
	return (var_key);
}

static void	add_var_new(t_infos *infos, char *str)
{
	char	*var_content;
	char	*var_key;

	if (ft_strchr(str, '=') == NULL)
		add_env_var(infos, str, NULL);
	else
	{
		var_content = get_var_content(infos, str);
		var_key = get_var_key(infos, str, var_content);
		if (!ft_isalpha(var_key[0]) && !(var_key[0] == '_'))
			return (ft_putstr_fd("Invalid variable name\n", 2), free(var_key));
		add_env_var(infos, var_key, var_content);
		free(var_key);
		free(var_content);
	}
}

int	update_path(t_infos *infos)
{
	char	*path;

	if (env_var_exists(infos, "PATH") == 1)
	{
		if ((infos)->paths != NULL)
			clear_tab((infos)->paths);
		path = get_env_var((infos), "PATH");
		if (!path)
			protect_memory(infos, 0, 0);
		(infos)->paths = ft_split(path, ':');
		if (!(infos)->paths)
			protect_memory(infos, path, 0);
		free(path);
	}
	else
	{
		if ((infos)->paths != NULL)
			clear_tab((infos)->paths);
		infos->paths = NULL;
	}
	return (0);
}

int	ft_export(t_infos *infos, t_cmd *cmd)
{
	char	*path;
	int		i;

	i = 1;
	if (cmd->args[1] == NULL)
		return (0);
	else if (cmd->args_indexes >= 3)
	{
		while (i < cmd->args_indexes - 1)
		{
			add_var_new(infos, cmd->args[i]);
			i++;
		}
		update_path(infos);
	}
	return (0);
}
