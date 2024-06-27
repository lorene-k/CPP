/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:41:42 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/26 16:56:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	parse_heredoc(t_token **token, t_cmd *cmd)
{
	cmd->file->heredoc = 1;
	cmd->file->limiter = ft_strdup((*token)->value);
	if ((*token)->next && (*token)->next->type == STRING)
	{
		(*token) = (*token)->next;
		cmd->file->name = ft_strdup((*token)->value); //check_this
	}
}

static void parse_outfile(t_token **token, t_cmd *cmd)
{
	cmd->file->name = ft_strdup((*token)->value);
	cmd->file->out = 1;
	if ((*token)->prev->value[1] == '>')
		cmd->file->append = 1;
}

void parse_infile(t_token **token, t_cmd *cmd)
{
	cmd->file->name = ft_strdup((*token)->value);
	cmd->file->in = 1;
}

static void	parse_redirect(t_token **token, t_cmd *cmd)
{
	(*token) = (*token)->next;
	add_node(0, 0, &(cmd->file));
	if ((*token)->prev->value[0] == '<' && !(*token)->prev->value[1])
		parse_infile(token, cmd);
	else if ((*token)->prev->value[0] == '>')
		parse_outfile(token, cmd);
	else
		parse_heredoc(token, cmd);
	if ((*token)->next && (*token)->next->type == REDIRECT)
		(*token) = (*token)->next;
}

int	handle_redirect(t_token **token, t_cmd *cmd)
{
	if (!(*token)->next || (*token)->next->type != STRING)
		return (print_error(INV_TOKEN, NULL, 2)); //CHECK_ERROR_HANDLING - adapt msg & exit code to diff cases
	while ((*token)->type == REDIRECT && (*token)->next
		&& (*token)->next->type == STRING)
	{
		if ((*token)->next->value[0] == '-')
			return (print_error(INV_TOKEN, NULL, 2));
		else
			parse_redirect(token, cmd);
	}
	return (0);
}