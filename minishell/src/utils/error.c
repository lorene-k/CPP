/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:27:37 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/15 15:18:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_error(char *msg, char *str, int code)
{
	ft_putstr_fd("minishell: ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putendl_fd(msg, 2);
	return (code);
}

int	protect_tab_memory(char **array)
{
	if (!array)
	{
		clear_tab(array);
		return (print_error(MALLOC_ERR, NULL, 1));
	}
	return (0);
}

int	protect_str_memory(char *str)
{
	if (!str)
		return (print_error(MALLOC_ERR, NULL, 1));
	return (0);
}