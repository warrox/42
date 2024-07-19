#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void ft_takefork(t_data *data, int i)
{
	pthread_mutex_lock(&data->philos->fork);
	// pthread_mutex_lock(&data->philos->write);
	printf("[🍴] %d has taken a fork\n",i);	
}

void *ft_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data *data = philo->data;
	int i = philo->id;
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
        {
            printf("Mutex initialization failed for philosopher %d\n", i);
            return((void*)-1);
        }

	ft_takefork(data, i);
	pthread_mutex_unlock(&data->philos->fork);
	pthread_mutex_lock(&data->write_mutex);
	sleep(1); // Simulate eating time
	printf("Philosopher is thinking[🤔]...\n");
	pthread_mutex_unlock(&data->write_mutex);
	sleep(1); // Simulate thinking 
	pthread_mutex_destroy(&data->write_mutex);
    return NULL;
}

int start_simulation(t_data *data)
{
    int i;
    pthread_t philo_threads[data->philo_nbr];
    data->philos = malloc(sizeof(t_philo) * data->philo_nbr);

    if (!data->philos)
        return (-1);

    for (i = 0; i < data->philo_nbr; i++)
    {
        data->philos[i].id  = i+1;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0)
        {
            printf("Mutex initialization failed for philosopher %d\n", i);
            return (-1);
        }
    }

    for (i = 0; i < data->philo_nbr; i++)
    {
        if (pthread_create(&philo_threads[i], NULL, ft_routine, (void *)&data->philos[i]) != 0)
        {
            printf("Error creating thread %d\n", i);
            return (-1);
        }
    }

    for (i = 0; i < data->philo_nbr; i++)
    {
        if (pthread_join(philo_threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            return (-1);
        }
    }

    for (i = 0; i < data->philo_nbr; i++)
    {
        pthread_mutex_destroy(&data->philos[i].fork);
    }

    free(data->philos);
	free(data->arrayofphilo);
    return (0);
}

int main(int argc, char **argv)
{
    t_data data;

    if (argc < 4)
    {
        printf("Not enough parameters, you should enter: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. Optional: [number_of_times_each_philosopher_must_eat]\n");
        printf("Exiting Philo\n");
        exit(EXIT_FAILURE);
    }

    ft_parser(argv, &data);
    start_simulation(&data);

    return (0);
}
