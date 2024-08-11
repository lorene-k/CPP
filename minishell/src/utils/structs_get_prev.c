/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_get_prev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/11 17:52:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void *get_prev_file(void *node)
{
    return ((t_file *)node)->prev;
}

static void *get_prev_cmd(void *node)
{
    return ((t_cmd *)node)->prev;
}

static void *get_prev_token(void *node)
{
    return ((t_token *)node)->prev;
}

static void *get_prev_node(void *last, void *(*get_prev)(void *))
{
    void	*curr;
	
    if (!last)
        return NULL;
	curr = last;
    while (get_prev(curr))
        curr = get_prev(curr);
    return (curr);
}

void	*get_first_node(t_token *token, t_cmd *cmd, t_file *file)
{
	if (token)
		return (get_prev_node(token, get_prev_token));
	if (cmd)
		return (get_prev_node(cmd, get_prev_cmd));
	if (file)
		return (get_prev_node(file, get_prev_file));
	return (NULL);
}
