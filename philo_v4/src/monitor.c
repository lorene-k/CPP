/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/17 19:21:10 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_philos(t_prog *prog)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (i < prog->data->n_philo)
	{
		ret = pthread_join(prog->philo[i].thread, NULL);
		if (ret != 0)
		{
			check_join(prog, ret);
			break ;
		}
		i++;
	}
}

static int	check_meals(t_prog *prog)
{
	int	i;

	i = 0;
	
	if (prog->data->meals_to_eat > 0)
	{
		while (i < prog->data->n_philo)
		{
			pthread_mutex_lock(&prog->philo[i].meal_m);
			if (prog->philo[i].meals_eaten  < prog->data->meals_to_eat)
				return (pthread_mutex_unlock(&prog->philo[i].meal_m), 0);
			i++;
		}
		pthread_mutex_unlock(&prog->philo[i].meal_m);
	}
	pthread_mutex_lock(&prog->data->dead_m);
	prog->data->dead_id = 0;
	pthread_mutex_unlock(&prog->data->dead_m); //PRINT STATUS ??
	return (1);
}

static int	check_death(t_prog *prog, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&prog->philo[i].time_m);
		pthread_mutex_lock(&prog->philo[i].meal_m);
		if ((get_time() - prog->philo[i].last_meal_time >= prog->data->death_time)
			&& !(prog->philo[i].eating))
		{
			pthread_mutex_unlock(&prog->philo[i].time_m);
			pthread_mutex_unlock(&prog->philo[i].meal_m);
			pthread_mutex_lock(&prog->data->dead_m);
			prog->data->dead_id = i;
			pthread_mutex_unlock(&prog->data->dead_m);
			return (1);
		}
		pthread_mutex_unlock(&prog->philo[i].time_m);
		pthread_mutex_unlock(&prog->philo[i].meal_m);
		i++;
	}
	return (0);
}

void	monitor(t_prog *prog, t_data *data)
{
	while (1)
	{
		if (check_death(prog, data) || check_meals(prog))
			break ;
	}
	if (prog->data->dead_id != -1)
		print_status(prog->philo, DIED);
	wait_for_philos(prog);
	destroy_mutexes(prog);
}
