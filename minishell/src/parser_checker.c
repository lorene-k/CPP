/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/18 17:21:01 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int get_cmd(t_token *token, t_data *data)
{
    if (token[0].type != STRING && token[0].type != KEYWORD)
        return (ft_putstr_fd(CMD_ERR, STDERR_FILENO), 1);
    
}

void    parser(t_token *token, t_data *data)
{
    if (get_cmd(token, data))
        return ;
}

/*
PARSER CHECKS  >> CLEAR OR SKIP NULL TOKENS ??
- 1st token is string or keyword

STEPS :
get_files(ac, av, &data);
get_cmds(ac, &data, envp);
get_fd(&data);
get_pipes(&data);
get_pids(&data);
*/
