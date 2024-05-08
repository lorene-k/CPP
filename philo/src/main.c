/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:13:03 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 22:27:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    main(int ac, char **av)
{
    t_data data;
    
    if (!check_args(ac, av))
        return (0);
    if (init_structs(ac, av, &data))
        return (destroy_mutexes(&data), 0);
    init_threads(&data); //PROTECT
    monitor(&data); //PROTECT
    return (0);
}

//destroy mutexes