/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:08:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/17 19:30:50 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	rest_and_think(t_philo *philo)
{
	print_status(philo, SLEEPING);
	ft_usleep(philo->data->sleep_time);
	if (is_dead(philo))
		return (1);
	print_status(philo, THINKING);
	return (0);
}

void	finish_eating(t_philo *philo)
{
	ft_usleep(philo->data->eat_time);
	pthread_mutex_lock(&philo->time_m);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->time_m);
	pthread_mutex_lock(&philo->meal_m);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_m);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	update_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_m);
	philo->meals_eaten += 1;
	philo->eating = 1;
	pthread_mutex_unlock(&philo->meal_m);
	print_status(philo, EATING);
}

int	take_forks(t_philo *philo)
{
	// if (philo->id % 2 == 0)
	// 	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, FORK_TAKEN);
	if (philo->data->n_philo == 1)
	{
		ft_usleep(philo->data->death_time);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	// if (philo->id % 2 == 0)
		// pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, FORK_TAKEN);
	return (0);
}

int	eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1); //TEST PRINT DEATH HERE
	update_status(philo);
	finish_eating(philo);
	return (0);
}
