/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/09 17:04:39 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_threads(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	if (philo)
		print_status(philo, DIED);
	pthread_mutex_lock(&data->philo->dead_m);
	while (i < philo->n_philo)
	{
		data->philo[i].dead = 1;
		i++;
	}
	pthread_mutex_unlock(&data->philo->dead_m);
}

static void	wait_for_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo->n_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

static int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo->meals_to_eat)
	{
		while (i < data->philo->n_philo)
		{
			pthread_mutex_lock(&data->philo->meal_m);
			if (data->philo[i].meals_to_eat != 0)
				return (pthread_mutex_unlock(&data->philo->meal_m), 0);
			pthread_mutex_unlock(&data->philo->meal_m);
			i++;
		}
		end_threads(data, -1);
	}
	return (1);
}

static int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo->n_philo)
	{
		pthread_mutex_lock(&data->philo->time_m);
		if ((get_time(data) - data->philo[i].last_meal_time >= data->philo->death_time)
			&& !(data->philo[i].eating))
		{
			pthread_mutex_unlock(&data->philo->time_m);
			end_threads(data, data->philo);
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor(t_data *data)
{
	while (1)
	{
		if (check_death(data) || check_meals(data))
			break ;
	}
	wait_for_philos(data);
	destroy_mutexes(data);
}
