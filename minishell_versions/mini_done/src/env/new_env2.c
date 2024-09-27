/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:47:46 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/13 17:02:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Obtient le nom de la variable d'environnement (premiere occurence)
static char	*get_first_var_key(char *str, size_t cursor)
{
	size_t	z;
	size_t	len_var_key;
	char	*var_key;

	len_var_key = 0;
	z = cursor;
	while (ft_isalnum(str[z]) && z++ < ft_strlen(str))
		len_var_key++;
	var_key = malloc(sizeof(char) * (len_var_key + 1));
	if (!var_key)
		return (NULL);
	z = 0;
	while (z < len_var_key)
	{
		var_key[z] = str[cursor + z];
		z++;
	}
	var_key[z] = '\0';
	return (var_key);
}

// Crée la premiere partie de la string lorsque l'on fait l'expansion
static char	*first_part_replace_one_var_sig(t_infos *infos, char *str,
		int heredoc, size_t i)
{
	char	*first;
	char	*second;
	char	*var_content;

	second = NULL;
	if (i == 0)
		first = ft_strdup("");
	else
		first = ft_substr(str, 0, i);
	if (!first)
		return (NULL);
	if (heredoc == 1)
		var_content = ft_itoa(infos->g_sig_id_heredoc);
	else
		var_content = ft_itoa(g_sig_id);
	if (var_content != NULL)
	{
		second = ft_strjoin(first, var_content);
		free(var_content);
	}
	return (free(first), second);
}

// Remplace la premiere occurence de $? par 127 par ex en partant de i
static char	*replace_one_return_code(t_infos *infos, char *str, size_t i,
		int heredoc)
{
	char	*second;
	char	*third;
	char	*final;

	second = first_part_replace_one_var_sig(infos, str, heredoc, i);
	if (!second)
		return (NULL);
	i++;
	while (ft_isalnum(str[i]) && i < ft_strlen(str))
		i++;
	third = ft_substr(str, i + 1, ft_strlen(str));
	if (!third)
		return (free(second), NULL);
	final = ft_strjoin(second, third);
	if (!final)
		return (free(second), free(third), NULL);
	return (free(second), free(third), final);
}

// Appele depuis replace_str_var_one_new (pour moins de 25 lignes)
static char	*manage_replace_str_one(t_infos *infos, char *str, size_t *cursor,
		size_t i)
{
	char	*var_key;
	char	*new_str;

	var_key = get_first_var_key(str, i);
	if (!var_key)
		return (NULL);
	new_str = replace_one_var_on_str_from_new(infos, str, var_key, i - 1);
	if (!new_str)
		return (free(var_key), NULL);
	*cursor = i;
	return (free(var_key), free(str), new_str);
}

// Retourne une nouvelle chaine avec une seule occurence de remplacée
char	*replace_str_var_one_new(t_infos *infos, char *str, int heredoc,
		size_t *cursor)
{
	size_t	i;
	char	*new_str;

	i = *cursor;
	while (i < ft_strlen(str))
	{
		if (str[i] == '$' && i + 1 < ft_strlen(str) && (ft_isalpha(str[i + 1])))
		{
			if (exp_check(str, i++) == 1)
				return (manage_replace_str_one(infos, str, cursor, i));
		}
		else if (str[i] == '$' && i + 1 < ft_strlen(str) && str[i + 1] == '?')
		{
			if (exp_check(str, i++) == 1)
			{
				new_str = replace_one_return_code(infos, str, i - 1, heredoc);
				*cursor = i;
				return (free(str), new_str);
			}
		}
		i++;
		*cursor = i;
	}
	return (str);
}
