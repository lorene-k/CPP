/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:16:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/23 05:21:32 by lkhalifa         ###   ########.fr       */
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

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	pthread_mutex_lock(&philo->data->start_m);
	pthread_mutex_unlock(&philo->data->start_m);
	if (philo->id % 2 == 0)
		usleep(philo->data->eat_time);
	if (!(philo->data->n_philo % 2 == 0)
		&& philo->data->n_philo > 2
		&& philo->id == philo->data->n_philo)
	{
		usleep(philo->data->eat_time + 10);
		// usleep(10);
		// print_status(philo, THINKING);
		// rest(philo);
	}
	while (!is_dead(philo))
	{
		if (eat(philo))
			break ;
		print_status(philo, THINKING);
		rest(philo);
	}
	return (p);
}

int	init_threads(t_prog *prog)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	// pthread_mutex_lock(&prog->data->start_m);
	while (i < prog->data->n_philo)
	{
		ret = pthread_create(&prog->philo[i].thread, NULL, &routine,
				&(prog->philo[i]));
		if (ret != 0)
			return (check_thread(prog, ret), 1);
		i++;
	}
	// pthread_mutex_unlock(&prog->data->start_m);
	return (0);
}
