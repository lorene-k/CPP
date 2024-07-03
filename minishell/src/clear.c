/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/30 12:52:09 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"
#include "../includes/minishell.h"

void    clear_all(void)
{
        // rl_clear_history();
        clear_history();
}

void	clear_tokens(t_token **start)
{
        t_token *current;
        t_token *next;

        if (!start|| !*start)
                return ;
        current = (*start);
	while (current)
	{
	        next = current->next;
                if (current->value)
                        free(current->value);
		free(current);
		current = next;
	}
        *start = NULL;
}
