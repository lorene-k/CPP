/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:41:42 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/15 18:17:49 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	parse_heredoc(t_token **token, t_cmd *cmd)
{
	cmd->file->heredoc = 1;
	cmd->file->limiter = ft_strdup((*token)->value);
	if (!cmd->file->limiter)
		return (print_error(MALLOC_ERR, NULL, 1));
	if ((*token)->next && (*token)->next->type == STRING)
	{
		(*token) = (*token)->next;
		cmd->file->name = ft_strdup((*token)->value);
	}
	return (protect_str_memory(cmd->file->name));
}

static int	parse_outfile(t_token **token, t_cmd *cmd)
{
	cmd->file->name = ft_strdup((*token)->value);
	cmd->file->out = 1;
	if ((*token)->prev->value[1] == '>')
		cmd->file->append = 1;
	return (protect_str_memory(cmd->file->name));
}

int	parse_infile(t_token **token, t_cmd *cmd)
{
	cmd->file->name = ft_strdup((*token)->value);
	cmd->file->in = 1;
	return (protect_str_memory(cmd->file->name));
}

static int	parse_redirect(t_token **token, t_cmd *cmd)
{
	(*token) = (*token)->next;
	add_node(0, 0, &(cmd->file));
	if (!cmd->file)
		return (print_error(MALLOC_ERR, NULL, 1));
	if ((*token)->prev->value[0] == '<' && !(*token)->prev->value[1])
		return (parse_infile(token, cmd));
	else if ((*token)->prev->value[0] == '>')
		return (parse_outfile(token, cmd));
	else
		return (parse_heredoc(token, cmd));
	if ((*token)->next && (*token)->next->type == REDIRECT)
		(*token) = (*token)->next;
	return (0);
}

int	handle_redirect(t_token **token, t_cmd *cmd)
{
	if (!(*token)->next || (*token)->next->type != STRING)
		return (print_error(INV_TOKEN, NULL, 2));
	while ((*token)->type == REDIRECT && (*token)->next
		&& (*token)->next->type == STRING)
	{
		if ((*token)->next->value[0] == '-')
			return (print_error(INV_TOKEN, NULL, 2));
		else
			return (parse_redirect(token, cmd));
	}
	return (0);
}