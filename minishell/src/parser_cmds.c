/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:38:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/09 17:14:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		get_args(token, cmd, arg_n);
	// printf("TEST 1 : token value = %s\n", (*token)->value);
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
			add_file(&cmd->file);
			parse_infile(token, cmd);
		}
	}
}
