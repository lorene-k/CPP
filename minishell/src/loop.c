/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:44:58 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/19 18:17:23 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parse.h"

static void scan(void)
{
    char    *line;
    
    line = readline("$minishell ");
    if (!line)
    {
        ft_putendl_fd("exit", 1);
        exit(0);
    }
    addhistory(line);
}

void run_loop(t_data *data)
{
    while (1)
    {
        scan();
        // parse(data);
        // exec(data);
        // clear(data);
        // sig_handler(data);
    }
}