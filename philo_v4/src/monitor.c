/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/16 16:57:42 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	end_threads(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->philo->dead_m);
	while (i < data->philo->n_philo)
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
		if (pthread_join(data->philo[i].thread, NULL) != 0)
		{
			printf(JOIN_ERR);
			break ;
		}
		i++;
	}
}

static int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->philo->meal_m);
	if (data->philo->meals_to_eat > 0)
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
		pthread_mutex_lock(&data->philo->meal_m);
		if ((get_time() - data->philo[i].last_meal_time >= data->philo->death_time)
			&& !(data->philo[i].eating))
		{
			pthread_mutex_unlock(&data->philo->time_m);
			pthread_mutex_unlock(&data->philo->meal_m);
			end_threads(data);
			return (1);
		}
		pthread_mutex_unlock(&data->philo->time_m);
		pthread_mutex_unlock(&data->philo->meal_m);
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
