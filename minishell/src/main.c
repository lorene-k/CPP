/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:40:34 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/18 17:31:35 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_data   init_data(char **envp)
{
    t_data data;
	
    data.in = -1;
	data.out = -1;
	data.cmd_n = 0;
    data.status = 0;
    data.pipes = 0;
	data.here_doc = 0;
    data.envp = ;
	data.limiter = NULL;
	data.in_err = -1;
	data.out_err = -1;
	data.cmd->paths = 0;
	data.cmd->args = 0;
	data.cmd->c_path = 0;
}

int main(char **envp)
{
    t_data data;
    
    data = init_data(envp);
    run_loop(&data);
    clear_all();
    return (0);
}