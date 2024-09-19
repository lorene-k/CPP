/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imounjed <imounjed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:54:56 by imounjed          #+#    #+#             */
/*   Updated: 2024/09/19 14:54:57 by imounjed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_key(t_infos *infos, char *str, char *var_content)
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

// Renvoi 1 si contient uniquement lettres, chiffres ou _ apres le premier char
int	contains_good_characters(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1)
	{
		while (str[i])
		{
			if (!ft_isalnum(str[i]) && !(str[i] == '_'))
				return (0);
			i++;
		}
	}
	return (1);
}

// Renvoi 1 si la cle pour la table denv est conforme
int	all_chars_good_key(char *str)
{
	if (!ft_isalpha(str[0]) && !(str[0] == '_'))
		return (ft_putstr_fd(" not a valid identifier\n", 2), 0);
	if (!contains_good_characters(str))
		return (ft_putstr_fd(" not a valid identifier\n", 2), 0);
	return (1);
}

int	add_var_new(t_infos *infos, char *str)
{
	char	*var_content;
	char	*var_key;

	if (ft_strchr(str, '=') == NULL)
	{
		if (all_chars_good_key(str) == 0)
			return (1);
		else
			add_env_var(infos, str, NULL);
	}
	else
	{
		var_content = get_var_content(infos, str);
		var_key = get_var_key(infos, str, var_content);
		if (!ft_isalpha(var_key[0]) && !(var_key[0] == '_'))
			return (ft_putstr_fd(" not a valid identifier\n", 2),
				free(var_content), free(var_key), 1);
		if (!contains_good_characters(var_key))
			return (ft_putstr_fd(" not a valid identifier\n", 2),
				free(var_content), free(var_key), 1);
		add_env_var(infos, var_key, var_content);
		free(var_key);
		free(var_content);
	}
	return (0);
}

// int