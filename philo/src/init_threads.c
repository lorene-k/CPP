/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:16:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/09 10:57:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_m);
	if (philo->dead)
		return (pthread_mutex_unlock(&philo->data->dead_m), 1);
	return (pthread_mutex_unlock(&philo->data->dead_m), 0);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	// if (philo->id % 2 == 0)
	// 	usleep(100); CHECK THIS IF ODD/EVEN NUMBER OF PHILOS
	while (!is_dead(philo))
	{
		eat(philo);
		rest(philo);
		think(philo);
	}
	return (p);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &routine,
				&(data->philo[i])));
			return (printf(THREAD_ERR), 1);
		i++;
	}
	return (0);
}
