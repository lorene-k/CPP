/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/28 22:01:57 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static void	get_fd(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	data->fd = malloc(sizeof(int *) * data->pipes);
// 	if (!data->fd)
// 		print_error("malloc", 0, data); //change print error here
// 	while (++i < data->pipes)
// 	{
// 		data->fd[i] = malloc(sizeof(int) * 2);
// 		if (!data->fd[i])
// 			print_error("malloc", 0, data);
// 	}
// }

static int    get_pipes(t_token *token)
{
    t_token *curr;
    int     pipes;

    curr = token;
    pipes = 0;
    while(curr)
    {
        if (curr->type == PIPE)
            pipes++;
        curr = curr->next;
    }
    return (pipes);
}

static void init_data(t_data *data, t_token *token, t_cmd *cmd)
{
    data->status = 0;
	data->here_doc = 0;
	data->limiter = NULL;
    data->pipes = get_pipes(token);
    data->epath = getenv("PATH");
	data->cmd_n = data->pipes + 1;
    data->cmd = cmd;
    // get_fds
    // get_pids
}

static int    handle_redirect(t_token **token, t_cmd *cmd, t_data *data)
{
    if (!(*token)->next)
        return (print_error(REDIRECT_ERR, NULL, 258)); //CHECK_ERROR_HANDLING
    else if ((*token)->next && (*token)->next->type == STRING)
        check_redirect((*token), cmd, data);
    if (data->here_doc)
        (*token) = (*token)->next;
    (*token) = (*token)->next;
    return (0);
}

static void check_cmd_args(t_token **token, t_cmd *cmd)
{
    int arg_n;
    t_token *curr;

    arg_n = 1;
    (*token) = (*token)->next;
    curr = (*token);
    while (curr->next && curr->type == STRING && *(curr->next->value) == '-')
    {
        curr = curr->next;
        arg_n++;
    }
    printf("TEST 2 : args = %d\n", arg_n);
    if (arg_n)
    {
        cmd->args = malloc(sizeof(char *) * arg_n + 1); // i + 1 ?
        if (!cmd->args)
        {    
            print_error(MALLOC_ERR, NULL, 1);
            clear_tab(cmd->args);   //clear_tab later in any case ?
        }
        cmd->args[arg_n] = NULL;
        while (--arg_n)
        {
            *(cmd->args) = ft_strdup((*token)->value);
            (*token) = (*token)->next;
            cmd->args++;
        }
    }
    // printf("current token->value = %s\n", (*token)->value);
    // int i = 0;
    // while (cmd->args[i++])
        printf("cmd->args[%d] = %s\n", 0, cmd->args[0]);
    // printf("token->value after cmd args = %s\n", token->value);
}

static void  get_cmd(t_token **token, t_cmd *cmd, t_data *data) // TEST THIS
{
    cmd->name = ft_strdup((*token)->value);
    if ((*token)->type == KEYWORD)
        cmd->builtin = 1;
    if ((*token)->next && (*token)->next->type == STRING
        && *((*token)->next->value) == '-')
        check_cmd_args(token, cmd);
    else if ((*token)->next && (*token)->next->type == STRING)
        get_file((*token)->next->value, cmd, 1, data);
}

static int check_token(t_token **token, t_cmd *cmd, t_data *data)
{
    if ((*token)->type == STRING  || (*token)->type == KEYWORD)
        {
            printf("TEST 1 - check token : cmd\n");
            return(get_cmd(token, cmd, data), 0);}
    if ((*token)->type == REDIRECT)
        {
            printf("TEST 1 - check token : redirect\n");
            return(handle_redirect(token, cmd, data));}
    else
        {
            printf("TEST 1 - check token : cmd error\n");
            return (print_error(INV_COMMAND, (*token)->value, 127));}
}

int    parser(t_token *token, t_data *data)
{
    t_cmd  *cmd;
    
    cmd = NULL;
    init_data(data, token, cmd);
    while (token)
    {
        if (!token->value)
            token = token->next;
        add_cmd(&cmd);
        if (!cmd)
            return(print_error(MALLOC_ERR, NULL, 1)); //check exit code + err msg
        while (token && token->type != PIPE)
        {
            if (check_token(&token, cmd, data))
                return (1); //HANDLE ERROR HERE
            token = token->next;
        }
    }
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
