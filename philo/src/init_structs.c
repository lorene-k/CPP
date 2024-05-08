/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:02:18 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 19:04:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].dead = 0;
		data->philo[i].eating = 0;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal_time = get_time(data);
		data->philo[i].l_fork = &data->forks[i];
		if (i == data->n_philo - 1)
			break ;
		data->philo[i].r_fork = &data->forks[i + 1];
		i++;
	}
	data->philo[i].r_fork = &data->forks[0];
}

static void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->dead_m, NULL);
	pthread_mutex_init(&data->print_m, NULL);
}

static void	init_data(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->start_time = get_time(data);
	data->error = 0;
	if (ac == 6)
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
}

int	init_structs(int ac, char **av, t_data *data)
{
	init_data(ac, av, data);
	init_mutexes(data);
	init_philos(ac, av, data);
	return (data->error);
}
