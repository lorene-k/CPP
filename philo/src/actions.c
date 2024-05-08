/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:08:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 19:30:45 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    eat(t_philo *philo)
{
    
}

void    sleep(t_philo *philo)
{
    
}

void    take_forks(t_philo *philo)
{}

void    update_status(t_philo *philo)
{}

void    finish_eating(t_philo *philo)
{}

void    think(t_philo *philo)
{
    
}


// THINK 
// - print msg

// SLEEP
// - print msg 
// - usleep

// EAT //take fork 1 THEN fork 2

// 1. TAKE FORKS
// - lock 1st fork
// - print msg (fork_taken)
// - lock 2nd fork 
// - print msg (fork_taken)

// 2. UPDATE STATUS
// - lock meal mutex
// - meals_eaten++
// - last_meal_time = get_time()
// - eating = 1
// unlock meal mutex

// 3. FINISH EATING
// - print msg (is eating)
// - usleep(eat_time)
// - eating = 0 // use mutex here <<
// - unlock forks



// CAS PARTICULIER 1 PHILO 
// if (philo->num_of_philos == 1)
// 	{
// 		ft_usleep(philo->time_to_die);
// 		pthread_mutex_unlock(philo->r_fork);
// 		return ;
// 	}