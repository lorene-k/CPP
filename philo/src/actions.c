/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:08:14 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 22:26:43 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    think(t_philo *philo)
{
    print_status(philo, THINKING);
}

void    rest(t_philo *philo)
{
    print_status(philo, SLEEPING);
    usleep(philo->data->sleep_time);
}

static void    finish_eating(t_philo *philo)
{
    print_status(philo, EATING);
    usleep(philo->data->eat_time);
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&philo->r_fork);
}

void    update_status(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->meal_m);
    philo->meals_eaten++;
    philo->last_meal_time = get_time(philo->data);
    // philo->eating = 1;
    pthread_mutex_unlock(&philo->data->meal_m);
}

static void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    print_status(philo, FORK_TAKEN);
    // handle solo philo case
    pthread_mutex_lock(philo->r_fork);
    print_status(philo, FORK_TAKEN);
}

void    eat(t_philo *philo)
{
    take_forks(philo);
    update_status(philo);
    finish_eating(philo);
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