/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/26 13:25:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_prog prog;
	t_data data;

	if (check_args(ac, av) || init_structs(ac, av, &data, &prog))
		return (1);
	if (init_threads(&prog))
		return (clean_all(&prog), 1);
	monitor(&prog, &data);
	return (0);
}
