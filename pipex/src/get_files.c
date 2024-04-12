/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:55:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/12 18:10:06 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_all_files(int files, char **av, t_data *data) //clear this
{
	char *file;
	char **tmp;
	int i;
	int j;

	i = 3;
	j = -1;
	data->files = malloc(sizeof(int) * files);
	while (++j < files)
	{
		tmp = ft_split(av[i++],' ');
		file = tmp[1 - ft_wcount(tmp, ' ')];
		clear_tab(tmp);
		data->files[j] = open(file, O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (data->files[j] < 0)
			check_error(data, file);
	}
}

void	get_out(char *out, t_data *data)
{
	if (data->here_doc)
		data->out = open(out, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		data->out = open(out, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (data->out < 0)
		check_error(data, out); // ERR HERE (check if command valid before printing)
}

void	get_in(char *in, t_data *data)
{
	if (data->here_doc)
		get_heredoc(data);
	else
	{
		data->in = open(in, O_RDONLY);
		if (data->in < 0)
			check_error(data, in);
	}
}

void	check_heredoc(int ac, char **av, t_data *data)
{
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		data->here_doc = 1;
		data->limiter = av[2];
		if (ac < 6)
		{
			ft_putstr_fd("pipex : Invalid number of arguments\n", 2);
			exit(1);
		}
	}
}

void	get_files(int ac, char **av, t_data *data)
{
	check_heredoc(ac, av, data);
	get_in(av[1], data);
	get_out(av[ac - 1], data);
	if (data->here_doc && ac >= 6 || ac >= 5)
		get_all_files(ac - 5 - data->here_doc, av, data);
}
