/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/23 12:49:54 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_token(t_token **token, t_cmd *cmd, t_data *d)
{
	if ((*token)->type == T_STRING || (*token)->type == T_KEYWORD)
		return (get_cmd(token, cmd, d));
	if ((*token)->type == T_REDIRECT)
		return (handle_redirect(token, cmd, d));
	return (print_error(INV_COMMAND, (*token)->value, 127, d)); //unnecessary - should be handled in exec
}

static int	parse_token(t_token **token, t_cmd *cmd, t_data *data) //loop on single cmd (before pipe)
{
	while ((*token) && (*token)->type != T_PIPE)
	{
		if (check_token(token, cmd, data))
		{
			cmd->file = get_first_node(0, 0, cmd->file);
			return (1);
		}
		if (*token && (*token)->type != T_PIPE)
			(*token) = (*token)->next;
	}
	if ((*token) && (*token)->type == T_PIPE && !(*token)->next)
		return (print_error(INV_TOKEN, NULL, 2, data));
	else if ((*token) && (*token)->type == T_PIPE)
		(*token) = (*token)->next;
	data->cmd_n++;
	cmd->file = get_first_node(0, 0, cmd->file);
	return (0);
}

void	parser(t_token *token, t_data *data)
{
	t_cmd *cmd;

	cmd = NULL;
	while (token)
	{
		add_node(0, &cmd, 0);
		if (!token->value || !token->type || !cmd) // check funcheck
		{
			print_error(MALLOC_ERR, NULL, 1, data); //check exit code + err msg
			break ;
		}
		if (parse_token(&token, cmd, data))
			break ;
	}
	data->pipes = data->cmd_n - 1;
	data->cmd = get_first_node(0, cmd, 0);
	// printf("PARSER TEST : cmd->name = %s\n", data->cmd->name);
}

/*
PARSER CHECKS  >> CLEAR OR SKIP NULL TOKENS ??
- 1st token is : redirect, cmd/built-in

if			t1 = redirect : 
- t2 = file
- t3 = cmd OR builtin

if			t1 = cmd :
- t2 = redirect OR str

< : input
> : output
>> : append ouput 
<< : heredoc

    SYNTAX of 1 cmd (before pipe)
- cmd (args) file
- cmd (args) [redirect] file 
- [redirect] file cmd (args)
- cmd (args) [redirect] infile [redirect] outfile
- << LIMITER (cmd) (file) {if }

STEPS
- check 1st token : either string or redirect
- if string or keyword : get name + check/get args (if keyword, set flag)
- if redirect : check that next token = file

AFTER CMD
- args
- file
- redirect




IN EXEC
- check if cmd == builtin 
- if not >> pipex
- if yes >> handle builtins (check flg for echo : removes nl ?)
*/
