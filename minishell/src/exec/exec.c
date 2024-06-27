/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:11:32 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/26 22:28:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Exit with Status: If the exit command has a second argument (e.g., exit 2), the shell converts it to an integer and uses it as the exit status.
Error Handling: If the argument is not numeric, the shell should print an error message and exit with a status of 255, which is standard behavior.*/

static int do_exit(t_data *data)
{
    if (data->cmd->file)
        // if not num : data->status = 255;
        // if num : data->status = num;
        // if more than 1 file : error msg : exit bash: exit: trop d'arguments >> CHECK
    data->quit = 1;
    return (1);
}

static int	check_builtin(t_data *data)
{
    if (ft_strncmp(data->cmd->name, "exit", 5) && ft_strlen(data->cmd->name) == 4)
        return (do_exit(data));
}

void	exec(t_data *data)
{
    if (check_builtin(data));
        return ;
}
