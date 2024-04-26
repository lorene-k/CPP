/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:55:12 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/04/25 16:37:11 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_out_error(char *out, t_data *data, char *in, int ac)
{
	data->out_err = 1;
	check_error(out, 1, data);
	put_in_error(data, in);
	if (ac == 5 || (data->here_doc && ac == 6))
		exit(1);
}

void	get_out(char *out, t_data *data, char *in, int ac)
{
	if (data->here_doc)
		data->out = open(out, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		data->out = open(out, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (data->out < 0)
		do_out_error(out, data, in, ac);
	else if (data->in < 0)
		put_in_error(data, in);
}

void	get_in(char *in, t_data *data)
{
	data->in = open(in, O_RDONLY);
	if (data->in < 0)
		check_error(in, 0, data);
}

void	get_files(int ac, char **av, t_data *data)
{
	get_in(av[1], data);
	get_out(av[ac - 1], data, av[1], ac);
}
