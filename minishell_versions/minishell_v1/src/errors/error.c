/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:53:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/29 17:41:23 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	protect_memory(t_infos *infos, char *str, char **tab)
{
	if (str)
		free(str);
	if (tab)
		clear_tab(tab);
	ft_putendl_fd("malloc: memory allocation failed", 2);
	free_infos_error(infos);
	exit(1);
}

int	print_cmd_error(char *msg, t_infos *infos, int code)
{
	if (infos)
		infos->return_code = code;
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(msg, 2);
	return (code);
}

void	free_infos_error(t_infos *infos) //TEST
{
	return ;
}
