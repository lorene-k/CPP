/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:38:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/01 17:46:56 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	parse_redirect(t_token **token, t_cmd *cmd, t_data *data)
{
	(*token) = (*token)->next;
	if ((*token)->prev->value[0] == '<')
		cmd->infile = ft_strdup((*token)->value);
	else if ((*token)->prev->value[0] == '>')
	{
		cmd->outfile = ft_strdup((*token)->value);
		if ((*token)->prev->value[1] == '>')
			cmd->append = 1;
	}
	else
	{
		// cmd->infile = HEREDOC; //check_this
		data->here_doc = 1;
		data->limiter = ft_strdup((*token)->value);
	}
}

int	handle_redirect(t_token **token, t_cmd *cmd, t_data *data)
{
	if (!(*token)->next || (*token)->next->type != STRING)
		return (print_error(INV_TOKEN, NULL, 2)); //CHECK_ERROR_HANDLING - adapt msg & exit code to diff cases
	else if ((*token)->next && (*token)->next->type == STRING)
		parse_redirect(token, cmd, data);
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
			cmd->args[i] = ft_strdup((*token)->value); // protect memory
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
			cmd->infile = ft_strdup((*token)->value);
	}
}
