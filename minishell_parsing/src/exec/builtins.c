/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:40:55 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 14:43:46 by lkhalifa         ###   ########.fr       */
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
    size_t  len;
    
    len = ft_strlen(data->cmd->name); 
    if (ft_compare_strings("exit", data->cmd->name, len));
        return (do_exit(data));
}