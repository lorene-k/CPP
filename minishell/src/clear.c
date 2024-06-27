/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/27 19:11:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void    clear_all(void)
{
        rl_clear_history();
        // free(line);
        // free_token(token);
        // free_error(error);
        // free_cmd(cmd);
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
                printf("%s\n", current->value);
	        next = current->next;
                if (current->value)
                        free(current->value);
		free(current);
		current = next;
	}
        *start = NULL;
}
