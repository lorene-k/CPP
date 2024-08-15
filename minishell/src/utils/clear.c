/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:37:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/15 15:42:59 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clear_file(t_file **current, t_file **next)
{
	*next = (*current)->next;
	if ((*current)->name)
		free((*current)->name);
	if ((*current)->limiter)
		free((*current)->limiter);
	free(*current);
	*current = *next;
}

static void	clear_cmd(t_cmd **current, t_cmd **next)
{
	*next = (*current)->next;
	clear_nodes((void *)&(*current)->file, sizeof(t_file)); //check syntax
	clear_tab((*current)->args);
	clear_tab((*current)->paths);
	if ((*current)->name)
		free((*current)->name);
	if ((*current)->c_path)
		free((*current)->c_path);
	free((*current));
	*current = *next;
}

static void	clear_token(t_token **current, t_token **next)
{
	(*next) = (*current)->next;
	if ((*current)->value)
		free((*current)->value);
	free((*current));
	*current = *next;
}

void	clear_nodes(void **start, size_t n_size)
{
	void	*current;
	void	*next;
	
	if (!start || !*start)
		return ;
	current = *start;
	next = NULL;
	while (current)
	{
		if (n_size == sizeof(t_token))
			clear_token((t_token **)&current, (t_token **)&next);
		else if (n_size == sizeof(t_cmd))
			clear_cmd((t_cmd **)&current, (t_cmd **)&next);
		else if (n_size == sizeof(t_file))
			clear_file((t_file **)&current, (t_file **)&next);
	}
	*start = NULL;
}

void	clear_parser(t_data *data, char *line, t_token *token)
{
	free(line);
	if (data->line)
		free(data->line);
	data->line = NULL;
	data->status = 0;
	if (token)
		clear_nodes((void **)&token, sizeof(t_token));
}
