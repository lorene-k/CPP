/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:02:18 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/17 19:18:21 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	init_philos(t_philo *philo, t_prog *prog, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].last_meal_time = get_time();
		philo[i].meals_eaten = 0;
		philo[i].l_fork = &prog->forks[i];
		philo[i].r_fork = &prog->forks[(i + 1) % data->n_philo];
		philo->data = data;
		i++;
	}
}

static void	init_mutexes(t_data *data, t_prog *prog)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&prog->forks[i], NULL);
		pthread_mutex_init(&prog->philo[i].time_m, NULL);
		pthread_mutex_init(&prog->philo[i].meal_m, NULL);
		i++;
	}
	pthread_mutex_init(&data->dead_m, NULL);
	pthread_mutex_init(&data->print_m, NULL);
}

static void	parse_args(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	data->start_time = get_time();
	data->dead_id = -1;
	if (ac == 6)
		data->meals_to_eat = ft_atoi(av[5]);
	else
		data->meals_to_eat = -1;
}

void	init_structs(int ac, char **av, t_data *data, t_prog *prog)
{
	t_philo	philo[200];

	prog->philo = philo;
	prog->data = data;
	philo->data = data;
	parse_args(ac, av, data);
	init_mutexes(data, prog);
	init_philos(philo, prog, data);
}
