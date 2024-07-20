/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/20 16:04:24 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

void ft_time(t_data *data)
{
	(void)data; 
	struct timeval *tv = NULL;
	struct timezone *tz = NULL;
	tv = malloc(sizeof(struct timeval));
	if(!tv)
		return;
	data->ms = 0;
	gettimeofday(tv, tz);
	data->ms = tv->tv_usec;
}

void ft_eat(t_data *data,int i)
{
	int t_e;
	t_e = data->time_eat;
	t_e = t_e * 1000;
	while(t_e)
	{
		pthread_mutex_lock(&data->write_mutex);
		ft_time(data);
		printf("%ld %d is eating[🍝]\n",data->ms, i);
		pthread_mutex_unlock(&data->write_mutex);
		sleep(1);//pas bon
		t_e --;	
	}
}

bool ft_takefork(t_data *data, int i)
{
	if(data->philo_nbr % 2 == 0)
	{
		pthread_mutex_lock(&data->philos[i].fork);
		pthread_mutex_lock(&data->philos[i+ 1].fork);
	}
	else {
		return(false);
	}
	ft_time(data);
	printf("%ld %d has taken a fork[🍴]\n",data->ms,i);
	return(true);
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

	if(ft_takefork(data, i) == true)
		ft_eat(data,i);
	pthread_mutex_unlock(&data->philos[i].fork);
	pthread_mutex_unlock(&data->philos[i + 1].fork);
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
	i = 0;
    pthread_t philo_threads[data->philo_nbr];
    data->philos = malloc(sizeof(t_philo) * data->philo_nbr);

    if (!data->philos)
        return (-1);

    while (i < data->philo_nbr)
    {
        data->philos[i].id  = i+1;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0)
        {
            printf("Mutex initialization failed for philosopher %d\n", i);
            return (-1);
        }
		i++;
    }
	i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_create(&philo_threads[i], NULL, ft_routine, (void *)&data->philos[i]) != 0)
        {
            printf("Error creating thread %d\n", i);
            return (-1);
        }
		i++;
    }

    i = 0;
	while (i < data->philo_nbr)
    {
        if (pthread_join(philo_threads[i], NULL) != 0)
        {
            printf("Error joining thread %d\n", i);
            return (-1);
        }
		i++;
    }
	i = 0;
    while(i < data->philo_nbr)
    {
        pthread_mutex_destroy(&data->philos[i].fork);
		i++;
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
	ft_time(&data);
    start_simulation(&data);

    return (0);
}
