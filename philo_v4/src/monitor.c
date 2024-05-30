/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/30 17:16:00 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_death(t_philo *philo, int i, t_data *data)
{
	long long	time;
	
	pthread_mutex_lock(&data->print_m);
	pthread_mutex_lock(&data->dead_m);
	data->dead_id = i;
	pthread_mutex_unlock(&data->dead_m);
	time = get_time() - data->start_time;
	printf("%lld %d %s\n", time, philo->id, DIED);
	printf("philo id : %d\nmeals eaten : %d \nmeals to eat : %d\n", philo->id, philo->meals_eaten, philo->data->meals_to_eat);
	pthread_mutex_unlock(&data->print_m);
}

static void	wait_for_philos(t_prog *prog)
{
	int	i;
	int	ret;

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
			if (prog->philo[i].meals_eaten < prog->data->meals_to_eat)
				return (pthread_mutex_unlock(&prog->philo[i].meal_m), 0);
			pthread_mutex_unlock(&prog->philo[i].meal_m);
			i++;
		}
		pthread_mutex_lock(&prog->data->print_m);
		pthread_mutex_lock(&prog->data->dead_m);
		prog->data->dead_id = i;
		printf("philo id : %d\nmeals eaten : %d \nmeals to eat : %d\n", prog->philo[1].id, prog->philo[0].meals_eaten, prog->data->meals_to_eat);
		pthread_mutex_unlock(&prog->data->print_m);
		pthread_mutex_unlock(&prog->data->dead_m);
		return (1);
	}
	return (0);
}

static int	check_death(t_prog *prog, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&prog->philo[i].meal_m);
		if ((get_time() - prog->philo[i].last_meal_time >= data->death_time))
		{
			print_death(&prog->philo[i], i, data);
			pthread_mutex_unlock(&prog->philo[i].meal_m);
			return (1);
		}
		pthread_mutex_unlock(&prog->philo[i].meal_m);
		i++;
	}
	return (0);
}

void	monitor(t_prog *prog, t_data *data)
{

	while (data->n_philo > 1 && 1)
	{

		if (check_death(prog, data) || check_meals(prog))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&data->print_m);
	wait_for_philos(prog);
	pthread_mutex_unlock(&data->print_m);
	clean_all(prog);
}
