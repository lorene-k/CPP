/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:33:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/15 16:18:44 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

static void cmd_tester(t_cmd *cmd, t_data *data) //TEST
{
	int i = -1;
	int j = 0;
	int k = 0;
	
	printf("CMD TESTER :\n");
    while(cmd)
	{
		if (cmd->name)
			printf("CMD %d: %s\n",++j, cmd->name);
		if (cmd->args)
		{
			while (cmd->args[++i])
				printf("cmd->args[%d] = %s\n", i, cmd->args[i]);
		}
		t_file *currfile = cmd->file;
		while (currfile)
		{
			if (currfile->name)
				printf("FILE %d = %s\n", ++k, currfile->name);
			if (currfile->in)
				printf(("IS IN\n"));
			else if (currfile->out)
				printf(("IS OUT\n"));
			if (currfile->append)
				printf("APPEND\n");
			if (currfile->heredoc)
				printf(("IS HEREDOC - limiter = %s\n"), currfile->limiter);
			currfile = currfile->next;
		}
		cmd = cmd->next;
	}
	if (data->pipes)
		printf("PIPES : %d\t", data->pipes);
	printf("CMD_N : %d\n", data->cmd_n);
	printf("SUCCESS\n");
}

static void init_data(t_data *data, char *line)
{
	data->cmd = NULL;
	data->cmd_n = 0;
    data->pipes = 0;
	data->quit = 0;
	data->line = NULL;
    data->epath = getenv("PATH");
	data->line = ft_strdup(line);
}

void	parse_input(t_data *data, char *line)
{
	t_token	*token;

	token = NULL;
	init_data(data, line);
	token = lexer(token, line, data);
	// lexer_tester(token); //TEST
	if (token)
		parser(token, data);
	if (data->cmd)
		cmd_tester(data->cmd, data); //TEST
	clear_parser(data, line, token);
}
