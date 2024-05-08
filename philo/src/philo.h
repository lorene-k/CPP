/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@42.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/08 22:27:03 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

/* LIBRARIES */
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* PHILO ACTIONS */
# define FORK_TAKEN "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

/* ERR MESSAGES */
# define INV_ARG_N "Error : invalid number of arguments\n"
# define INV_CHAR "Error : invalid character\n"
# define INV_ARGS "Error : invalid argument(s)\n"
# define TIME_ERR "Error : gettimeofday() crashed\n"
# define THREAD_ERR "Error : pthread_create() crashed\n"

/* STRUCTS */
typedef struct s_philo
{
	int				id;
	int				dead;
	int eating; //use this ??
	int				meals_eaten;
	int				last_meal_time;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

}					t_philo;

typedef struct s_data
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				start_time;
	int				meals;
	int				error;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	meal_m;
	pthread_mutex_t	dead_m;
	pthread_mutex_t	print_m;
}					t_data;

/* CHECK & INIT */
int					check_args(int ac, char **av);
int					init_structs(int ac, char **av, t_data *data);

/* INIT_THREADS */
void				*routine(void *p);
int					init_threads(t_data *data);

/* ACTIONS */
void				think(t_philo *philo);
void				rest(t_philo *philo);
void				update_status(t_philo *philo);
void				eat(t_philo *philo);

/* MONITOR */
void				monitor(t_data *data);

/* UTILS */
void				destroy_mutexes(t_data *data);
void				print_status(t_philo *philo, char *s);
int					get_time(t_data *data);
int					ft_atoi(const char *str);

#endif // PHILO_H