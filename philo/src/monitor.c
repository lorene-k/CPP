/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/10 13:13:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo->n_philo)
	{
		pthread_mutex_lock(&data->philo[i].dead_m);
		data->philo[i].dead = 1;
		pthread_mutex_unlock(&data->philo[i].dead_m);
		i++;
	}
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
	pthread_mutex_lock(&data->philo->meal_m);
	if (data->philo->meals_to_eat != -1)
	{
		while (i < data->philo->n_philo)
		{
			
			if (data->philo[i].meals_to_eat != 0)
				return (pthread_mutex_unlock(&data->philo->meal_m), 0);
			i++;
		}
		pthread_mutex_unlock(&data->philo->meal_m);
		end_threads(data);
	}
	pthread_mutex_unlock(&data->philo->meal_m);
	return (1);
}

static int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo->n_philo)
	{
		pthread_mutex_lock(&data->philo->time_m);
		if ((get_time(&data->philo[i]) - data->philo[i].last_meal_time >= data->philo->death_time)
			&& !(data->philo[i].eating))
		{
			pthread_mutex_unlock(&data->philo->time_m);
			end_threads(data);
			return (1);
		}
		pthread_mutex_unlock(&data->philo->time_m);
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
