/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:19:06 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 19:30:58 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    wait_for_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_philo)
    {
        pthread_join(data->philo[i].thread, NULL); //PROTECT ??
        i++;
    }
}

void    monitor(t_data *data)
{
    while (!check_death(data))
    {
        if (check_meals(data))
            break ;
    }
    // wait_for_philos(data);
    destroy_mutexes(data);
}


// DO 
// - CHECK MEALS
// - CHECK DEATH 
// - HANDLE DEATH