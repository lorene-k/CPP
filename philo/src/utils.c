/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:44:00 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 22:12:18 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->meal_m);
	pthread_mutex_destroy(&data->dead_m);
	pthread_mutex_destroy(&data->print_m);
}

void	print_status(t_philo *philo, char *s)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->print_m);
	time = get_time(philo->data) - philo->data->start_time; //check where to put start time (in philos or data struct?)
	printf("%zd %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->data->print_m);
}

int	get_time(t_data *data)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		data->error = 1;
		return (printf(TIME_ERR), -1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * sign);
}
