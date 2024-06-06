/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:39 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/06/06 13:57:53 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_thread(t_prog *prog, int ret)
{
	pthread_mutex_lock(&prog->data->print_m);
	if (ret == EAGAIN)
		printf("Error: Insufficient resources to create another thread\n");
	else if (ret == EINVAL)
		printf("Error: Invalid settings in thread attributes\n");
	else if (ret == EPERM)
		printf("Error: No permission to set scheduling policy and parameters\n");
	else
		printf("Unknown error");
	pthread_mutex_unlock(&prog->data->print_m);
}

void	check_join(t_prog *prog, int ret)
{
	pthread_mutex_lock(&prog->data->print_m);
	if (ret == ESRCH)
		printf("Error: No thread found with the specified ID\n");
	else if (ret == EINVAL)
		printf("Error: The thread is not a joinable thread\n");
	else if (ret == EDEADLK)
		printf("Error: Deadlock detected or joining itself\n");
	else if (ret == ENOMEM)
		printf("Error: Insufficient memory to join the thread\n");
	else
		printf("Unknown error");
	pthread_mutex_unlock(&prog->data->print_m);
}
