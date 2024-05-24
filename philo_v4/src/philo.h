/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalifa <lkhalifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:22:45 by lkhalifa          #+#    #+#             */
/*   Updated: 2024/05/24 18:23:34 by lkhalifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

/* ------------  LIBRARIES  ------------------------------------------------ */
# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* ------------  MACROS  --------------------------------------------------- */
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
# define JOIN_ERR "Error : pthread_join() crashed\n"

/* ------------  STRUCTS  -------------------------------------------------- */
typedef struct s_data
{
	int				n_philo;
	int				dead_id;
	long long		death_time;
	int				eat_time;
	int				sleep_time;
	long long		start_time;
	int				meals_to_eat;
	pthread_mutex_t	start_m;
	pthread_mutex_t	dead_m;
	pthread_mutex_t	print_m;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal_time;
	int				meals_eaten;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	meal_m;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct s_prog
{
	t_data			*data;
	t_philo			*philo;
	pthread_mutex_t	forks[200];
}					t_prog;

/* ------------  FUNCTIONS  ------------------------------------------------ */
/* UTILS */
void				destroy_mutexes(t_prog *prog);
void				print_status(t_philo *philo, char *s);
void				ft_usleep(int ms, t_philo *philo);
int					ft_atoi(const char *str);

/* CHECK & INIT */
int					check_args(int ac, char **av);
long long			get_time(void);
void				init_data(int ac, char **av, t_data *data);
void				init_mutexes(t_data *data, t_prog *prog);
void				init_structs(int ac, char **av, t_data *data, t_prog *prog);

/* ACTIONS */
void				solo_philo(t_philo *philo);
int					rest(t_philo *philo);
void				drop_forks(t_philo *philo);
int					take_forks(t_philo *philo);
int					eat(t_philo *philo);

/* INIT_THREADS */
int					is_dead(t_philo *philo);
void				*routine(void *p);
int					init_threads(t_prog *prog);

/* ERRORS */
void				check_thread(t_prog *prog, int ret);
void				check_join(t_prog *prog, int ret);

/* MONITOR */
void				print_death(t_philo *philo, int i, t_data *data);
void				wait_for_philos(t_prog *prog);
int					check_meals(t_prog *prog);
int					check_death(t_prog *prog, t_data *data);
void				monitor(t_prog *prog, t_data *data);

#endif //PHILO_H
