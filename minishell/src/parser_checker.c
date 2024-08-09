/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/08/09 17:04:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void init_data(t_data *data, t_cmd *cmd)
{
    data->status = 0;
    data->pipes = 0;
    data->epath = getenv("PATH");
	data->cmd_n = 0;
    data->cmd = cmd;
}

static int check_token(t_token **token, t_cmd *cmd)
{
    if ((*token)->type == STRING  || (*token)->type == KEYWORD)
        return(get_cmd(token, cmd), 0);
    if ((*token)->type == REDIRECT)
        return(handle_redirect(token, cmd));
    return (print_error(INV_COMMAND, (*token)->value, 127));
}

static int parse_token(t_token **token, t_cmd *cmd, t_data *data)
{
    while ((*token) && (*token)->type != PIPE)
    {
        if (check_token(token, cmd))
            return (1);     //HANDLE ERROR HERE
        if (*token)
            (*token) = (*token)->next;
    }
    if ((*token) && (*token)->type == PIPE && !(*token)->next)
        return (print_error(INV_TOKEN, NULL, 2));
    else if ((*token) && (*token)->type == PIPE)
        (*token) = (*token)->next;
    data->cmd_n++;
    return (0);
}

int    parser(t_token *token, t_data *data)
{
    t_cmd  *cmd;
    
    cmd = NULL;
    init_data(data, cmd);
    while (token)
    {
        if (!token->value)
            token = token->next;
        add_cmd(&cmd);
        if (!cmd)
            return(print_error(MALLOC_ERR, NULL, 1)); //check exit code + err msg
        if (parse_token(&token, cmd, data))
            return (1); // return parse_token ?
        cmd->file = get_first_file(cmd->file);
    }
    data->pipes = data->cmd_n - 1;
    data->cmd = get_first_cmd(cmd);
    // printf("PARSER TEST : cmd->name = %s\n", data->cmd->name);
    return (0);
}

/*
PARSER CHECKS  >> CLEAR OR SKIP NULL TOKENS ??
- 1st token is : redirect, cmd/built-in

if t1 = redirect : 
- t2 = file
- t3 = cmd OR builtin

if t1 = cmd :
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
