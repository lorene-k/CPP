/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/01 17:12:39 by lkhalifa         ###   ########.fr       */
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
	printf("CMD TESTER :\ncmd->name = %s\n", data->cmd->name);
	int i = -1;
    if (data->cmd->args)
	{
		while (data->cmd->args[++i])
        printf("cmd->args[%d] = %s\n", i, data->cmd->args[i]);
	}
	if (data->cmd->infile)
		printf("INFILE = %s\n", data->cmd->infile);
	if (data->cmd->outfile)
		printf("OUTFILE = %s\n", data->cmd->outfile);
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
