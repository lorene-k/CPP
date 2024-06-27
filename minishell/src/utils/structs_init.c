/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:09:59 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/26 16:58:13 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_cmds(void *node, void **current)
{
	t_cmd *cmd;
	
	cmd = (t_cmd *)node;
	cmd->name = NULL;
	cmd->args = NULL;
	cmd->paths = NULL;
	cmd->c_path = NULL;
	cmd->file = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	cmd->builtin = 0;
	if (*current)
	{
		((t_cmd *)(*current))->next = node;
		((t_cmd *)node)->prev = *current;
	}
}

static void	init_files(void *node, void **current)
{
	t_file *file;
	
	file = (t_file *)node;
	file->name = NULL;
	file->in = 0;
	file->out = 0;
	file->append = 0;
	file->fd_in = 0;
	file->fd_out = 0;
	file->heredoc = 0;
	file->limiter = NULL;
	file->next = NULL;
	file->prev = NULL;
	if (*current)
	{
		((t_file *)(*current))->next = node;
		((t_file *)node)->prev = *current;
	}
}

static void	init_tokens(void *node, void **current)
{
	t_token *token;

	token = (t_token *)node;
	token->value = NULL;
	token->type = -1;
	token->next = NULL;
	token->prev = NULL;
	if (*current)
	{
		((t_token *)(*current))->next = node;
		((t_token *)node)->prev = *current;
	}
}

static void	get_node(void **curr, size_t n_size, void (*init)(void *, void **))
{
	void	*node;

	node = malloc(n_size);
	if (!node)
	{
		clear_nodes(curr, n_size);
		*curr = NULL;
		return ;
	}
	init(node, curr);
	*curr = node;
}

void	add_node(t_token **token, t_cmd **cmd, t_file **file)
{
	if (token)
		get_node((void **)token, sizeof(t_token), init_tokens);
	if (cmd)
		get_node((void **)cmd, sizeof(t_cmd), init_cmds);
	if (file)
		get_node((void **)file, sizeof(t_file), init_files);
}
