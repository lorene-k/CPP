/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/24 23:09:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static void	get_fd(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	data->fd = malloc(sizeof(int *) * data->pipes);
// 	if (!data->fd)
// 		print_error("malloc", 0, data);
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
	data->cmd_n = data->pipes + 1;
    data->status = 0;
	data->here_doc = 0;
	data->limiter = NULL;
    data->pipes = get_pipes(token);
    data->epath = getenv("PATH");
    data->cmd = cmd;
    // get_fds
    // get_pids
}

static int    handle_redirect(t_token *token, t_cmd *cmd, t_data *data)
{
    if (!token->next)
        return (print_error(REDIRECT_ERR, 258)); //CHECK_ERROR_HANDLING
    else if (token->next && token->next->type == STRING)
        check_redirect(token, cmd, data);
    if (data->here_doc)
        token = token->next;
    token = token->next;
    return (0);
}

static int check_token(t_token *token, t_cmd *cmd, t_data *data)
{
    if (token->type == REDIRECT)
        return(handle_redirect(token, cmd, data));
    // if (token->type == STRING )
    //     return (get_cmd(token, cmd));
    // if (token->type == KEYWORD)
    //     return (check_builtin(token, data));
    return (printf("ERROR TEST\n"));
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
            return(print_error(MALLOC_ERR, 1));
        if (check_token(token, cmd, data))
            return (1); //HANDLE ERROR HERE
        token = token->next;
    }
    return (0);
}

/*
PARSER CHECKS  >> CLEAR OR SKIP NULL TOKENS ??
- 1st token is : redirect, cmd, built-in

if t1 = redirect : 
- t2 = file
- t3 = cmd OR builtin

if t1 = cmd :
- t2 = redirect OR str

STEPS :
get_files(ac, av, &data);
get_cmds(ac, &data, envp);
get_fd(&data);
get_pipes(&data);
get_pids(&data);
*/
