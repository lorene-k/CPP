/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:38:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/16 15:03:27 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	get_cmd_flags(t_token **token, t_cmd *cmd, int arg_n, t_data *d)
{
	int	i;

	i = -1;
	cmd->args = malloc(sizeof(char *) * arg_n + 1);
	protect_tab_memory(cmd->args, d);
	(*cmd->args) = NULL;
	while (++i < arg_n)
	{
		cmd->args[i] = ft_strdup((*token)->value);
		protect_tab_memory(cmd->args, d);
		(*token) = (*token)->next;
	}
}

static void	check_cmd_flags(t_token **token, t_cmd *cmd, t_data *d)
{
	int		arg_n;
	t_token	*curr;

	arg_n = 1;
	curr = (*token);
	while (curr->next && curr->type == T_STRING && *(curr->next->value) == '-')
	{
		curr = curr->next;
		arg_n++;
	}
	if (arg_n)
		get_cmd_flags(token, cmd, arg_n, d);
}

static int	is_cmd_arg(t_token *token)
{
	if (token && (token->type == T_STRING || token->type == T_CHAR
			|| token->type == T_INT || token->type == T_KEYWORD))
		return (1);
	return (0);
}

static int	check_cmd_args(t_token **token, t_cmd *cmd, t_data *d)
{
	if (is_cmd_arg((*token)->next))
	{
		(*token) = (*token)->next;
		if (*((*token)->value) == '-')
			check_cmd_flags(token, cmd, d);
		while (is_cmd_arg((*token)))
		{
			add_node(0, 0, &(cmd->file));
			if (!cmd->file)
				return (print_error(MALLOC_ERR, NULL, 1, d));
			if (parse_infile(token, cmd, d))
				return (1);
			(*token) = (*token)->next;
		}
	}
	return (0);
}

int	get_cmd(t_token **token, t_cmd *cmd, t_data *d)
{
	cmd->name = ft_strdup((*token)->value);
	if (!cmd->name)
		return (print_error(MALLOC_ERR, NULL, 1, d));
	if ((*token)->type == T_KEYWORD)
		cmd->builtin = 1;
	return (check_cmd_args(token, cmd, d));
}
