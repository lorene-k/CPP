/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:53:53 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/05 17:02:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Appele lors quun malloc pete
void	protect_memory(t_infos *infos, char *str, char **tab)
{
    if (infos)
        infos->printed_error = 1;
	if (str)
		free(str);
	if (tab)
		clear_tab(tab);
	ft_putendl_fd("malloc: memory allocation failed", 2);
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
