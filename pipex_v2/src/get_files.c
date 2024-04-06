/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:55:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/05 17:13:08 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_out(char *out, t_data *data)
{
	if (data->here_doc)
		data->out = open(out, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		data->out = open(out, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (data->out < 0)
		check_error(data);// ERR HERE (check if command valid before printing)
}

void	get_in(char **av, t_data *data)
{
	if (data->here_doc)
		get_heredoc(data);
	else
	{
		data->in = open(av[1], O_RDONLY);
		if (data->in < 0)
			check_error(data);
		// check msg + look for err_code // exit code == 1 (use struct)
		// get msg + err_code 
		// display msg AFTER cmd not found
		// "cat: okk: No such file or directory"
	}
}

void	check_heredoc(int ac, char **av, t_data *data)
{
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		data->here_doc = 1;
		data->limiter = av[2];
		if (ac != 6)
		{
			ft_putstr_fd("pipex : Invalid number of arguments\n", 2);
			exit(1);
		}
	}
}

void	get_files(int ac, char **av, t_data *data)
{
	check_heredoc(ac, av, data);
	get_in(av, data);
	get_out(av[ac - 1], data);
}