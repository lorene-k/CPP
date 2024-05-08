/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 22:23:28 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void    wait_for_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        pthread_join(data->philo[i].thread, NULL); //PROTECT ??
        i++;
    }
}

static int check_meals(t_data *data)
{
    int i;

    i = 0;
    if (data->meals)
    {
        while (i < data->n_philo)
        {
            pthread_mutex_lock(&data->meal_m);
            if (data->philo[i].meals_eaten != data->meals)
                return (pthread_mutex_unlock(&data->meal_m), 1);
            pthread_mutex_unlock(&data->meal_m);
            i++;
        }
        // handle_all_meals_eaten(data)
    }
    return (0);
}

static int check_death(t_data *data)
{
    int i;
    
    i = 0;
    while (i < data->n_philo)
    {
        pthread_mutex_lock(&data->dead_m);
        if (data->philo[i].dead)
            return (handle_death(data), 1);
        pthread_mutex_lock(&data->dead_m);
        i++;
    }
    return (0);
}

void    monitor(t_data *data)
{
    while (1)
    {
        if (check_death(data) || check_meals(data))
            break ;
    }
    wait_for_philos(data);
    destroy_mutexes(data);
}

// - Handle all meals eaten
// - HANDLE DEATH