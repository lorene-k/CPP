/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:44:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/20 00:38:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


static void scan(t_data *data)
{
    char    *line;
    
    line = readline();
    if (!line)
    {
        ft_putendl_fd("exit", 1);
        exit(0);
    }
    exit(2);
}

void run_loop(t_data *data)
{
    while (1)
    {
        scan(data);
        // parse_line(data, line);
        // check_syntax(data);
        // parse_token(data);
        // exec(data);
        // clear_line(data);
    }
}