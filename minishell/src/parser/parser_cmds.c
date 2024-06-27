/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:38:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/26 22:13:58 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void get_args(t_token **token, t_cmd *cmd, int arg_n)
{
	int i;

	i = -1;
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

static void	check_cmd_flags(t_token **token, t_cmd *cmd)
{
	int		arg_n;
	t_token	*curr;

	arg_n = 1;
	curr = (*token);
	while (curr->next && curr->type == STRING && *(curr->next->value) == '-')
	{
		curr = curr->next;
		arg_n++;
	}
	if (arg_n)
		get_args(token, cmd, arg_n);
	// printf("TEST 1 : token value = %s\n", (*token)->value);
}

static int	is_cmd_arg(t_token *token)
{
	if (token && (token->type == STRING
		|| token->type == INT || token->type == KEYWORD))
		return (1);
	return (0);
}

void		get_cmd(t_token **token, t_cmd *cmd)
{
	cmd->name = ft_strdup((*token)->value);
	if ((*token)->type == KEYWORD)
		cmd->builtin = 1;
	if (is_cmd_arg((*token)->next))
	{
		(*token) = (*token)->next;
		if (*((*token)->value) == '-')
			check_cmd_flags(token, cmd);
		while (is_cmd_arg((*token)))
		{	
			add_node(0, 0, &(cmd->file));
			parse_infile(token, cmd);
			(*token) = (*token)->next;
		}
	}
}
