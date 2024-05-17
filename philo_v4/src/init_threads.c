/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:16:11 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/17 19:25:36 by lkhalifa         ###   ########.fr       */
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
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->death_time);
	while (!is_dead(philo))
	{
		if (eat(philo))
			break ;
		rest_and_think(philo);
	}
	return (p);
}

int	init_threads(t_prog *prog)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (i < prog->data->n_philo)
	{
		ret = pthread_create(&prog->philo[i].thread, NULL, &routine, &(prog->philo[i]));
		if (ret != 0)
			return (check_thread(prog, ret), 1);
		i++;
	}
	return (0);
}
