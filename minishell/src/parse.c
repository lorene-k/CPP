/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/28 19:16:41 by lkhalifa         ###   ########.fr       */
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

static void cmd_tester(t_cmd *cmd) //TEST
{
	t_cmd *curr;

	curr = cmd;
	printf("CMD TESTER : cmd->name = %s\n", curr->name);
	// while (curr)
	// {
	// 	printf("IN LOOP cmd tester :\n");
	// 	next = curr->next;
	// 	printf("CMD TESTER : cmd in/out = %d\n", cmd->in); //TEST
	// 	curr = next;
	// }
	// exit(0);
}

void	parse_input(t_data *data, char *line)
{
	t_token	*token;

	token = NULL;
	token = lexer(token, line);
	// lexer_tester(token); //TEST
	parser(token, data);
	cmd_tester(data->cmd); //TEST
	free(line);
	clear_tokens(&token);
}
