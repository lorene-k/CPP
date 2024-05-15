/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:02:18 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/15 12:43:17 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].dead = 0;
		philo[i].eating = 0;
		philo[i].start_time = get_time();
		philo[i].last_meal_time = philo[i].start_time;
		philo[i].l_fork = &data->forks[i];
		if (i == philo->n_philo - 1)
			break ;
		philo[i].r_fork = &data->forks[i + 1];
		i++;
	}
	philo[i].r_fork = &data->forks[0];
}

static void	init_mutexes(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->dead_m, NULL);
	pthread_mutex_init(&philo->print_m, NULL);
	pthread_mutex_init(&philo->meal_m, NULL);
	pthread_mutex_init(&philo->time_m, NULL);
}

static void	parse_args(int ac, char **av, t_philo *philo)
{
	philo->n_philo = ft_atoi(av[1]);
	philo->death_time = ft_atoi(av[2]);
	philo->eat_time = ft_atoi(av[3]);
	philo->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		philo->meals_to_eat = ft_atoi(av[5]);
	else
		philo->meals_to_eat = -1;
}

void	init_structs(int ac, char **av, t_data *data)
{
	t_philo philo[200];
	
	data->philo = philo;
	parse_args(ac, av, philo);
	init_mutexes(data, philo);
	init_philos(philo, data);
}
