/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:16:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/30 17:12:52 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_m);
	if (philo->data->dead_id != -1)
		return (pthread_mutex_unlock(&philo->data->dead_m), 1);
	return (pthread_mutex_unlock(&philo->data->dead_m), 0);
}

static void think(t_philo *philo)
{
	long long time;

	if (!is_dead(philo))
	{	
		print_status(philo, THINKING);
		time = get_time();
		if (philo->data->n_philo % 2 != 0
			&& (philo->data->eat_time + philo->data->sleep_time < time - philo->last_meal_time))
				ft_usleep(philo->data->sleep_time + 100, philo);
	}
}

static void	sync_philos(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->start_m);
	pthread_mutex_unlock(&philo->data->start_m);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10, philo);
	if (philo->id == philo->data->n_philo && philo->data->n_philo % 2 != 0
		&& philo->data->n_philo > 2)
		ft_usleep(philo->data->eat_time, philo);
}

static void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	sync_philos(philo);
	while (!is_dead(philo))
	{
		if (eat(philo))
			break ;
		if (is_dead(philo) || rest(philo))
			break ;
		think(philo);
	}
	return (p);
}

int	init_threads(t_prog *prog)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < prog->data->n_philo)
	{
		ret = pthread_create(&prog->philo[i].thread, NULL, &routine,
				&(prog->philo[i]));
		if (ret != 0)
			return (check_thread(prog, ret), 1);
		i++;
	}
	return (0);
}
