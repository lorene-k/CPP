/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/05 22:47:05 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static void lexer_tester(t_token *token) //TEST
// {
// 	t_token *curr;
// 	t_token *next;
// 	int     i;

// 	i = 0;
// 	curr = token;
// 	while (curr)
// 	{
// 		next = curr->next;
// 		printf("LEXER TESTER : token %d value : %s\t type : %d\n\n", i,
// 				curr->value, curr->type); //TEST
// 		curr = next;
// 		i++;
// 	}
// 	// exit(0);
// }

static void cmd_tester(t_data *data) //TEST
{
	int i = -1;
	int j = 0;
	printf("CMD TESTER :\n");
    while(data->cmd)
	{
		printf("CMD %d: %s\n",++j, data->cmd->name);
		if (data->cmd->args)
		{
			while (data->cmd->args[++i])
			printf("cmd->args[%d] = %s\n", i, data->cmd->args[i]);
		}
		if (data->cmd->file)
			printf("FILE = %s\n", data->cmd->file->name);
		if (data->cmd->file->limiter)
			printf("LIMITER = %s\n", data->cmd->file->limiter);
		data->cmd = data->cmd->next;
	}
	if (data->pipes)
		printf("PIPES : %d\t", data->pipes);
	printf("CMD_N : %d\n", data->cmd_n);
	printf("SUCCESS\n");
	// exit(0);
}

void	parse_input(t_data *data, char *line)
{
	t_token	*token;

	token = NULL;
	token = lexer(token, line);
	// lexer_tester(token); //TEST
	parser(token, data);
	cmd_tester(data); //TEST
	free(line);
	clear_tokens(&token);
}
