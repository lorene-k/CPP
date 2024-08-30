/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:27:37 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 14:04:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_error(char *msg, char *str, int code, t_data *data)
{
	ft_putstr_fd("minishell: ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	ft_putendl_fd(msg, 2);
	data->status = code;
	return (code);
}

int	protect_tab_memory(char **array, t_data *data)
{
	if (!array)
	{
		clear_tab(array);
		return (print_error(MALLOC_ERR, NULL, 1, data));
	}
	return (0);
}

int	protect_str_memory(char *str, t_data *data)
{
	if (!str)
		return (print_error(MALLOC_ERR, NULL, 1, data));
	return (0);
}
