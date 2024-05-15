/* INIT STRUCTS - OK */
void	test_init(t_data data)
{
	printf("PHILO :\n");
	printf("id : %d\n", data.philo[0].id);
	printf("eating : %d\n", data.philo[0].eating);
	printf("meals to eat : %d\n", data.philo[0].meals_to_eat);
	printf("last meal time : %d\n\n", data.philo[0].last_meal_time);

	printf("DATA :\n");
	printf("n_philo : %d\n", data.philo->n_philo);
	printf("death time : %d\n", data.philo->death_time);
	printf("eat time : %d\n", data.philo->eat_time);
	printf("sleep time: %d\n", data.philo->sleep_time);
	printf("start time: %d\n", data.philo->start_time);
	printf("error: %d\n", data.philo->error);
	printf("death: %d\n", data.philo->dead);
	exit (0);
}