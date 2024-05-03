/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:21:35 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/03 17:16:26 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

static int	is_valid_arg(int ac, char **av)
{
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 60
		|| ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (printf(INV_ARGS), 0);
	if (ac == 6 && av[5] < 0)
		return (printf(INV_ARGS), 0);
	return (1);
}

static int	is_number(char *s, char *base)
{
	while (*s)
	{
		while (*base)
		{
			if (*s == *base)
				return (1);
			base++;
		}
		s++;
	}
	return (0);
}

static int	is_valid_number(char **av)
{
	while (*av)
	{
		if (!is_number(*av, "0123456789"))
			return (printf(INV_CHAR), 0);
		av++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (printf(INV_ARG_N), 0);
	if (!is_valid_number(av))
		return (0);
	return (is_valid_arg(ac, av));
}
