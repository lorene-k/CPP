/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/03 17:15:41 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    main(int ac, char **av)
{
    if (!check_args(ac, av))
        return (0);
}

// all in ms :

// number_of_philosophers 
// time_to_die
// time_to_eat 
// time_to_sleep

// optional : number_of_times_each_philosopher_must_eat