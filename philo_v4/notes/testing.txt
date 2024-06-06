/* INIT STRUCTS - OK */
static void	test_init(t_data data, t_prog prog)
{
	printf("PHILO :\n");
	printf("id : %d\n", prog.philo[0].id);
	printf("eating : %d\n", prog.philo[0].eating);
	printf("meals to eat : %d\n", prog.philo[0].meals_to_eat);
	printf("last meal time : %lld\n\n", prog.philo[0].last_meal_time);

	printf("DATA :\n");
	printf("n_philo : %d\n", data.n_philo);
	printf("data : meals to eat : %d\n", data.meals_to_eat);
	printf("death time : %d\n", data.death_time);
	printf("eat time : %d\n", data.eat_time);
	printf("sleep time: %d\n", data.sleep_time);
	printf("start time: %lld\n", data.start_time);
	printf("death: %d\n", data.dead_id);
	exit (0);
}


/* MONITOR */
	// pthread_mutex_lock(&data->print_m);
	// printf("eating : %d\nnow time : %lld - last meal time : %lld == %lld \n>= death time : %lld", prog->philo[0].eating, get_time(), prog->philo[0].last_meal_time, (get_time() - prog->philo[0].last_meal_time),prog->data->death_time);
	// pthread_mutex_unlock(&data->print_m);