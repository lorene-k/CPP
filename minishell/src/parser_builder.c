/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:38:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/05 22:43:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	parse_redirect(t_token **token, t_cmd *cmd)
{
	(*token) = (*token)->next;
	add_file(&cmd->file);
	if ((*token)->prev->value[0] == '<')
	{	
		cmd->file->name = ft_strdup((*token)->value);
		cmd->file->in = 1;
	}
	else if ((*token)->prev->value[0] == '>')
	{
		cmd->file->name = ft_strdup((*token)->value);
		cmd->file->out = 1;
		if ((*token)->prev->value[1] == '>')
			cmd->file->append = 1;
	}
	else
	{
		// cmd->infile = HEREDOC; //check_this
		cmd->file->heredoc = 1;
		cmd->file->limiter = ft_strdup((*token)->value);
	}
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

static void	check_cmd_args(t_token **token, t_cmd *cmd)
{
	int		i;
	int		arg_n;
	t_token	*curr;

	i = -1;
	arg_n = 1;
	curr = (*token);
	while (curr->next && curr->type == STRING && *(curr->next->value) == '-')
	{
		curr = curr->next;
		arg_n++;
	}
	if (arg_n)
	{
		cmd->args = malloc(sizeof(char *) * arg_n + 1);
		protect_memory(cmd->args);
		(*cmd->args) = NULL;
		while (++i < arg_n)
		{
			cmd->args[i] = ft_strdup((*token)->value);
			protect_memory(cmd->args);
			(*token) = (*token)->next;
		}
	}
}

void	get_cmd(t_token **token, t_cmd *cmd)
{
	cmd->name = ft_strdup((*token)->value);
	if ((*token)->type == KEYWORD)
		cmd->builtin = 1;
	if ((*token)->next && (*token)->next->type == STRING)
	{
		(*token) = (*token)->next;
		if (*((*token)->value) == '-')
			check_cmd_args(token, cmd);
		if (*token)
		{	
			cmd->file->name = ft_strdup((*token)->value);
			cmd->file->in = 1;
		}
	}
}
