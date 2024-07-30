/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/30 16:17:30 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_lib.h"
#include <pthread.h>
#include <stdio.h>
bool check_flag(t_data *data)
{
	pthread_mutex_lock(&data->flag_mutex);
	if(data->flag == 1)
	{
		pthread_mutex_unlock(&data->flag_mutex);
		return(true);
	}
	pthread_mutex_unlock(&data->flag_mutex);
	return(false);
}
void *ft_isdying(void *arg) 
{
    t_data *data = (t_data *)arg;
	int i = 0;
	while (1) 
	{    
		i = 1;
		while (i <= data->philo_nbr) 
        {
			if (ft_time() - data->philos[i].last_meal > data->time_die && data->philos[i].id != 0)
			{   
				pthread_mutex_lock(&data->flag_mutex);
				data->flag = 1;
				pthread_mutex_unlock(&data->flag_mutex);
				pthread_mutex_lock(&data->write_mutex);
				printf("%ld %d died\n", (ft_time()- data->ms), data->philos[i].id);
                pthread_mutex_unlock(&data->write_mutex);
				return(NULL);
            }
			i++;
        }
        usleep(1000); // Check every 1 millisecond
    }
    return NULL;
}

void ft_usleep(int time, t_data *data) 
{
    int end_time = ft_time()+ time;
    (void) data;
	while (ft_time() <= end_time) 
    {
		usleep(1000); // Sleep for a short duration to prevent busy-waiting
    }
}

void ft_issleeping(t_data *data, int i) 
{
    pthread_mutex_lock(&data->write_mutex);
    printf("%ld %d is sleeping[😴]\n", ft_time() - data->ms, i);
    pthread_mutex_unlock(&data->write_mutex);
    ft_usleep(data->time_sleep, data);
}

void ft_eat(t_data *data, int i) 
{
    pthread_mutex_lock(&data->write_mutex);
    data->philos[i].last_meal = ft_time();
    printf("%ld %d is eating[🍝]\n", ft_time() - data->ms, i);
    pthread_mutex_unlock(&data->write_mutex);
    ft_usleep(data->time_eat, data);
}

bool ft_takefork(t_data *data, int i) 
{
    int left_fork = i % data->philo_nbr;
    int right_fork = (i + 1) % data->philo_nbr;

    if (i == data->philo_nbr - 1) 
    {
        pthread_mutex_lock(&data->philos[right_fork].fork);
        pthread_mutex_lock(&data->write_mutex);
		printf("%ld %d has taken a right fork[🍴]\n", ft_time() - data->ms, i);
		pthread_mutex_unlock(&data->write_mutex);
        pthread_mutex_lock(&data->philos[left_fork].fork);
        pthread_mutex_lock(&data->write_mutex);
		printf("%ld %d has taken a left fork[🍴]\n", ft_time() - data->ms, i);
		pthread_mutex_unlock(&data->write_mutex);
    } 
    else 
    {
        pthread_mutex_lock(&data->philos[left_fork].fork);
		//lock avec write mutex
		pthread_mutex_lock(&data->write_mutex);
		printf("%ld %d has taken a left fork[🍴]\n",ft_time() - data->ms, i);
        pthread_mutex_unlock(&data->write_mutex);
		pthread_mutex_lock(&data->philos[right_fork].fork);
		pthread_mutex_lock(&data->write_mutex);
		printf("%ld %d has taken a right fork[🍴]\n", ft_time() - data->ms, i);
		pthread_mutex_unlock(&data->write_mutex);
    }
	pthread_mutex_unlock(&data->philos[i % data->philo_nbr].fork);
	pthread_mutex_unlock(&data->philos[(i + 1) % data->philo_nbr].fork); 
    return true;
}

void *ft_routine(void *arg) 
{
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data;
    int i = philo->id;

    while (1) 
    {
        if(check_flag(data)== true)
			break;
		ft_takefork(data, i);
		if(check_flag(data)== true)
			break;
        ft_eat(data, i);
		if(check_flag(data)== true)
			break;
		ft_issleeping(data, i);
		if(check_flag(data)== true)
			break;
        pthread_mutex_lock(&data->write_mutex);
        printf("%ld %d is thinking[🤔]...\n", ft_time() - data->ms, i);
        pthread_mutex_unlock(&data->write_mutex);
		if(check_flag(data)== true)
			break;
    }
    return NULL;
}

int start_simulation(t_data *data) 
{
    int i = 0;
    data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
    if (!data->philos)
        return -1;

    if (pthread_mutex_init(&data->write_mutex, NULL) != 0) 
    {
        printf("Write mutex initialization failed\n");
        return -1;
    }
	if (pthread_mutex_init(&data->flag_mutex, NULL) != 0) 
    {
        printf("Write mutex initialization failed\n");
        return -1;
    }
	while (i < data->philo_nbr) 
    {
        data->philos[i].id = i + 1;
        data->philos[i].data = data;
        if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0) 
        {
            printf("Mutex initialization failed for philosopher %d\n", i);
            return -1;
        }
        i++;
    }

    i = 0;
    while (i < data->philo_nbr) 
    {
		data->philos[i].last_meal = ft_time(); 
		if (pthread_create(&data->philos[i].thread, NULL, ft_routine, (void *)&data->philos[i]) != 0) 
        {
            printf("Error creating thread %d\n", i);
            return -1;
        }
        usleep(50);
        i++;
    }

	if (pthread_create(&data->die_thread, NULL, ft_isdying, (void *)data) != 0) 
    {
        printf("Error creating death monitoring thread\n");
        return -1;
    }

    i = 0;
    while (i < data->philo_nbr) 
    {
        if (pthread_join(data->philos[i].thread, NULL) != 0) 
        {
            printf("Error joining thread %d\n", i);
            return -1;
        }
        i++;
    }

    i = 0;
    while (i < data->philo_nbr) 
    {
        pthread_mutex_destroy(&data->philos[i].fork);
        i++;
    }

    pthread_mutex_destroy(&data->write_mutex);
    free(data->philos);
    return 0;
}

int main(int argc, char **argv) 
{
    t_data data;
	data.flag = 0;
    if (argc < 5) 
    {
        printf("Not enough parameters, you should enter: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. Optional: [number_of_times_each_philosopher_must_eat]\n");
        printf("Exiting Philo\n");
        exit(EXIT_FAILURE);
    }

    if (ft_parser(argv, &data) == -1)
        return -1;
    printf("sleep : %d\n", data.time_sleep);
	printf("eat : %d\n", data.time_eat);
	data.ms = ft_time();
	start_simulation(&data);

    return 0;
}
