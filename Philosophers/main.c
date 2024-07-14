#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>

int start_simulation(t_data *data)
{
	pthread_t threads[data->philo_nbr];
	int thread_ids[data->philo_nbr];
	pthread_mutex_t table;
	if(pthread_mutex_init(&table,NULL) != 0 )
		return(-1);
	return(0);
	while(data->time_die != 0)
	{
		data->time_die --;
		pthread_create(data->philo, NULL, (void *)start_simulation(data), &thread_ids[data->philo_nbr]);
	}
}
int main(int argc, char **argv)
{
	t_data data;
	if(argc < 4) // check if correct
	{
		printf("Not enough parameters, you should enter :  number_of_philosophers , time_to_die time_to_eat time_to_sleep, Optional : [number_of_times_each_philosopher_must_eat]\n");
		printf("Exiting Philo\n");
		exit(EXIT_FAILURE);
	}
	ft_parser(argv, &data);
	start_simulation(&data);
}
