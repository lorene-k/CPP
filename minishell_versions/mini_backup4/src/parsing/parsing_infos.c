/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:50:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/13 15:59:37 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes_new(char *s)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '|')
			words++;
		i++;
	}
	return (words);
}

// Duplique le tableau de variable d'environnement (envp)
static char	**dup_env_new(t_infos *infos)
{
	int		i;
	char	**new;

	i = 0;
	while (infos->new_envp[i] != NULL)
		i++;
	new = ft_calloc(sizeof(char *), (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (infos->new_envp[i] != NULL)
	{
		new[i] = ft_strdup(infos->new_envp[i]);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

static int	create_path(t_infos **infos)
{
	char	*path;
	int		ret;

	ret = env_var_exists(*infos, "PATH");
	if (ret == 1)
	{
		path = get_env_var((*infos), "PATH");
		if (!path)
			protect_memory(*infos, NULL, NULL);
		(*infos)->paths = ft_split(path, ':');
		free(path);
		if (!(*infos)->paths)
			protect_memory(*infos, path, NULL);
	}
	else if (ret == -1)
		free_infos_error(*infos);
	else
		path = NULL;
	return (0);
}

// Crée la structure infos et y associe quelques valeurs
void	create_infos(t_infos **infos, char *str, char **envp)
{
	char	*path;
	int		ret;

	*infos = ft_calloc(sizeof(t_infos), 1);
	if (!(*infos))
		protect_memory(*infos, NULL, NULL);
	(*infos)->pipes_nb = count_pipes_new(str);
	(*infos)->new_envp = envp;
	(*infos)->new_envp = dup_env_new(*infos);
	if (!(*infos)->new_envp)
		protect_memory(*infos, NULL, NULL);
	create_path(infos);
	(*infos)->input = str;
}
