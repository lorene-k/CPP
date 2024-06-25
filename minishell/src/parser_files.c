/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:38:09 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/24 23:10:25 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	get_heredoc(char *limiter, t_cmd *cmd, t_data *data)
{
	data->here_doc = 1;
	data->limiter = limiter;
	cmd->in = open(HEREDOC, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (cmd->in < 0)
		check_error(HEREDOC, 0, data);
}

static void	get_out(char *out, t_cmd *cmd, int type, t_data *data)
{
	if (type == 1)
	{	
		printf("TEST : OUT\n");
		cmd->out = open(out, O_CREAT | O_RDWR | O_TRUNC, 0000644);}
	else if (type == 2)
		cmd->out = open(out, O_CREAT | O_RDWR | O_APPEND, 0000644);
	if (cmd->out < 0)
		check_error(out, 0, data);
}

static void	get_in(char *in, t_cmd *cmd, t_data *data)
{
	cmd->in = open(in, O_RDONLY);
	if (cmd->in < 0)
		check_error(in, 0, data);
}

void		get_file(char *file, t_cmd *cmd, int type, t_data *data)
{
	if (type == 1)
		get_in(file, cmd, data);
	if (type == 2)
		get_out(file, cmd, 1, data);
	if (type == 3)
		get_heredoc(file, cmd, data); // DO THIS
	if (type == 4)
		get_out(file, cmd, 2, data);
}

void check_redirect(t_token *token, t_cmd *cmd, t_data *data)
{
	if (token->value[0] == '<') // redirect in
        get_file(token->next->value, cmd, 1, data);
    else if (token->value[0] == '>') // redirect out
        get_file(token->next->value, cmd, 2, data);
    else if (token->value[0] == '<' && token->value[1] == '<') // heredoc
        get_file(token->next->value, cmd, 3, data);
    else
        get_file(token->next->value, cmd, 4, data); // append out
}