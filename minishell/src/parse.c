/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/09 17:51:29 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void lexer_tester(t_token *token) //TEST
{
	t_token *curr;
	t_token *next;
	int     i;

	i = 0;
	curr = token;
	while (curr)
	{
		next = curr->next;
		printf("LEXER TESTER : token %d value : %s\t type : %d\n\n", i,
				curr->value, curr->type); //TEST
		curr = next;
		i++;
	}
	// exit(0);
}

// static void cmd_tester(t_data *data) //TEST
// {
// 	int i = -1;
// 	int j = 0;
// 	int k = 0;
// 	printf("CMD TESTER :\n");
//     while(data->cmd)
// 	{
// 		printf("CMD %d: %s\n",++j, data->cmd->name);
// 		if (data->cmd->args)
// 		{
// 			while (data->cmd->args[++i])
// 			printf("cmd->args[%d] = %s\n", i, data->cmd->args[i]);
// 		}
// 		while (data->cmd->file)
// 		{
// 			printf("FILE %d = %s\n", ++k, data->cmd->file->name);
// 			if (data->cmd->file->in)
// 				printf(("IS IN\n"));
// 			else if (data->cmd->file->out)
// 				printf(("IS OUT\n"));
// 			if (data->cmd->file->append)
// 				printf("APPEND\n");
// 			if (data->cmd->file->heredoc)
// 				printf(("IS HEREDOC - limiter = %s\n"), data->cmd->file->limiter);
// 			data->cmd->file = data->cmd->file->next;
			
// 		}
// 		data->cmd = data->cmd->next;
// 	}
// 	if (data->pipes)
// 		printf("PIPES : %d\t", data->pipes);
// 	printf("CMD_N : %d\n", data->cmd_n);
// 	printf("SUCCESS\n");
// 	// exit(0);
// }

void	parse_input(t_data *data, char *line)
{
	t_token	*token;

	token = NULL;
	token = lexer(token, line, data);
	free(data->line);
	free(line);
	lexer_tester(token); //TEST
	exit (0);
	parser(token, data);
	// cmd_tester(data); //TEST
	clear_tokens(&token);
}
