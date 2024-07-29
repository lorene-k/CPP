/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_files_draft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:06:57 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/07/29 16:07:23 by lkhalifa         ###   ########.fr       */
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
