#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *philo_eat_thread(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    printf("GOIN\n");

    while (1) // Simulating the philosopher eating indefinitely for demonstration purposes
    {
        pthread_mutex_lock(&philo->fork);
        printf("Philosopher is eating...\n");
        sleep(1); // Simulate eating time
        pthread_mutex_unlock(&philo->fork);
        printf("Philosopher is thinking...\n");
        sleep(1); // Simulate thinking time
    }

    return NULL;
}

int start_simulation(t_data *data)
{
    int i;
    pthread_t philo_threads[data->philo_nbr];
    data->philos = malloc(sizeof(t_philo) * data->philo_nbr);

    if (!data->philos)
        return -1;

    // Initialize mutexes and philosopher data
    for (i = 0; i < data->philo_nbr; i++)
    {
        if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0)
        {
            printf("Mutex initialization failed for philosopher %d\n", i);
            return -1;
        }
    }

    // Create philosopher threads
    for (i = 0; i < data->philo_nbr; i++)
    {
        if (pthread_create(&philo_threads[i], NULL, philo_eat_thread, (void *)&data->philos[i]) != 0)
        {
            printf("Error creating thread %d\n", i);
            return -1;
        }
    }

    // Join philosopher threads
    for (i = 0; i < data->philo_nbr; i++)
    {
        if (pthread_join(philo_threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            return -1;
        }
    }

    // Destroy mutexes
    for (i = 0; i < data->philo_nbr; i++)
    {
        pthread_mutex_destroy(&data->philos[i].fork);
    }

    free(data->philos);
    return 0;
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

    return 0;
}
