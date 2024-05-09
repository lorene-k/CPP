/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:08:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/09 17:41:33 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rest_and_think(t_philo *philo)
{
	print_status(philo, SLEEPING);
	usleep(philo->sleep_time);
	print_status(philo, THINKING);
}

void	finish_eating(t_philo *philo)
{
	print_status(philo, EATING);
	usleep(philo->eat_time);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&philo->time_m);
	philo->last_meal_time = get_time(philo);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->time_m);
}

void	update_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_m);
	philo->meals_to_eat -= 1;
	philo->eating = 1;
	pthread_mutex_unlock(&philo->meal_m);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, FORK_TAKEN);
	if (philo->n_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		usleep(philo->death_time);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, FORK_TAKEN);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	update_status(philo);
	finish_eating(philo);
}
