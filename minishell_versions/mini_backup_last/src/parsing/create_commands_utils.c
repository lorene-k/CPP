/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:28:41 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/19 14:29:48 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Renvoie le nombre de commandes totales
int	commands_nb(char **cmd_array)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (cmd_array[i] != NULL)
	{
		if (cmd_array[i + 1] == NULL)
		{
			nb++;
		}
		else if (ft_strcmp(cmd_array[i], "|") == 0)
		{
			nb++;
		}
		i++;
	}
	return (nb);
}
