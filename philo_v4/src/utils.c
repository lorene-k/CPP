/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:44:00 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/17 19:11:02 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->data->n_philo)
	{
		pthread_mutex_destroy(&prog->forks[i]);
		pthread_mutex_destroy(&prog->philo[i].time_m);
		pthread_mutex_destroy(&prog->philo[i].meal_m);
		i++;
	}
	pthread_mutex_destroy(&prog->data->dead_m);
	pthread_mutex_destroy(&prog->data->print_m);
}

void	print_status(t_philo *philo, char *s)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print_m);
	time = get_time() - philo->data->start_time;
	printf("%lld %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->data->print_m);
}

void	ft_usleep(int ms)
{
	long long	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms * 100); //CHECK THIS
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
