/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:27:01 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:59 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

static int	check_valid_arg(t_cmd *cmd, t_infos *infos)
{
	int	invalid_char;

	invalid_char = check_digit(cmd->args[1]);
	if (invalid_char)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putendl_fd(EXIT_NUM_ERR, 2);
		return (2);
	}
	return (ft_atoi(cmd->args[1]));
}

static int	check_arg_n(t_infos *infos, t_cmd *cmd)
{
	if (cmd->args_indexes > 3 && ft_isdigit(cmd->args[1][0]))
	{
		infos->return_code = 1;
		return (print_cmd_error(EXIT_ARG_ERR, infos, 1));
	}
	return (0);
}

int	ft_exit(t_infos *infos, t_cmd *cmd)
{
	ft_putendl_fd("exit", 1);
	if (check_arg_n(infos, cmd))
		return (1);
	if (cmd->args_indexes > 2)
		infos->return_code = check_valid_arg(cmd, infos);
	exit(infos->return_code);
}
