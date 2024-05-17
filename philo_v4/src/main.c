/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/17 19:04:03 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_prog prog;
	t_data data;

	if (check_args(ac, av))
		return (1);
	init_structs(ac, av, &data, &prog);
	// printf("%lld %d %lld\n", prog.data->start_time, prog.data->meals_to_eat, data.start_time);
	// exit(0);
	if (init_threads(&prog))
		return (1);
	monitor(&prog, &data);
	return (0);
}
