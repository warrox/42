/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/23 16:51:17 by bvan-pae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"

void ft_issleeping(t_data *data, int i)
{
	long chrono =  (data->time_sleep - data->ms) / 10;
	while(1)
	{
		pthread_mutex_lock(&data->write_mutex);
		ft_time(data);
		printf("%ld %d is sleeping[😴]\n",data->ms, i);
		pthread_mutex_unlock(&data->write_mutex);
		if(data->ms > chrono)
			break;
	}

}

void ft_eat(t_data *data,int i)
{
	ft_time(data);
	data->philos[i].last_meal = data->ms;
	ft_time(data);
	long chrono =  (data->time_eat - data->ms) / 10;
	if(chrono < 0)
		chrono = chrono * -1;
	while(1)
	{
		pthread_mutex_lock(&data->write_mutex);
		ft_time(data);
		if(data->ms > chrono)
			break;
	}
	printf("%ld %d is eating[🍝]\n",data->ms, i);
	pthread_mutex_unlock(&data->write_mutex);
}

bool ft_takefork(t_data *data, int i)
{
	if(data->philo_nbr % 2 == 0)
	{
		pthread_mutex_lock(&data->philos[i % data->philo_nbr].fork);
		pthread_mutex_lock(&data->philos[(i+ 1) % data->philo_nbr].fork);
	}
	else 
		return(false);
	ft_time(data);
	printf("%ld %d has taken a fork[🍴]\n",data->ms,i);
	printf("%ld %d has taken a fork[🍴]\n",data->ms,i);
	return(true);
}

void ft_isdying(t_data *data) 
{
    int i = 0;
    while (i < data->philo_nbr) 
	{
        ft_time(data);
        long time_since_last_meal = data->ms - data->philos[i].last_meal;
        if (time_since_last_meal > data->time_die) 
		{
            pthread_mutex_lock(&data->write_mutex);
            printf("%ld %d died\n", data->ms, data->philos[i].id);
            pthread_mutex_unlock(&data->write_mutex);
            exit(EXIT_FAILURE);
        }
        i++;
    }
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
	{
		ft_eat(data,i);
		ft_issleeping(data, i);
	}
	pthread_mutex_unlock(&data->philos[i % data->philo_nbr].fork);
	pthread_mutex_unlock(&data->philos[(i + 1) % data->philo_nbr].fork);
	pthread_mutex_lock(&data->write_mutex);
	printf("Philosopher is thinking[🤔]...\n");
	ft_time(data);
	ft_isdying(data);
	pthread_mutex_unlock(&data->write_mutex);
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

    // init mutex must create a func
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
    // create thread with instruction in ft_routibe for every threads
	while (i < data->philo_nbr)
    {
        ft_time(data);
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

    if(ft_parser(argv, &data) == -1)
		return(-1);
	ft_time(&data);
    start_simulation(&data);

    return (0);
}
